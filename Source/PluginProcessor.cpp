/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "KAPParameters.h"

//==============================================================================
KadenzeAudioPluginAudioProcessor::KadenzeAudioPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
        parameters(*this,
                   nullptr,
                   juce::Identifier("KAP"),
                   createParameterLayout())
#endif
{
    initializeDSP();    
    mPresetManager = std::make_unique<KAPPresetManager>(this);

}

KadenzeAudioPluginAudioProcessor::~KadenzeAudioPluginAudioProcessor()
{
}

//==============================================================================
const String KadenzeAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KadenzeAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KadenzeAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KadenzeAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KadenzeAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KadenzeAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String KadenzeAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void KadenzeAudioPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void KadenzeAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    for(int i = 0; i < 2; i++){
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]->setSampleRate(sampleRate);
    }
}

void KadenzeAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    for(int i = 0; i < 2; i++){
        mDelay[i]->reset();
        mLfo[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KadenzeAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void KadenzeAudioPluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        float inputGain = *parameters.getRawParameterValue(KAPParameterID[kParameter_InputGain]);
        
        mInputGain[channel]->process(channelData,
                                inputGain,
                                channelData,
                                buffer.getNumSamples());
        
        float modulationRate = *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationRate]);
        
        float rate = (channel==0) ? modulationRate : 0;
        
        float modulationDepth = *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationDepth]);
        
        mLfo[channel]->process(rate, modulationDepth, buffer.getNumSamples());
        
       float delayTime = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayTime]);
        float feedback = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayFeedback]);
        float wetDry = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayWetDry]);
        float delayType = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType]);
        
        mDelay[channel]->process(channelData,
                                 delayTime,
                                 feedback,
                                 wetDry,
                                 delayType,
                                 mLfo[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
        float outputGain = *parameters.getRawParameterValue(KAPParameterID[kParameter_OutputGain]);
        mOutputGain[channel]->process(channelData,
                                      outputGain,
                                      channelData,
                                      buffer.getNumSamples());
    }
}

//==============================================================================
bool KadenzeAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* KadenzeAudioPluginAudioProcessor::createEditor()
{
    return new KadenzeAudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void KadenzeAudioPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    XmlElement preset("KAP_StateInfo");
    XmlElement* presetBody = new XmlElement("KAP_Preset");
    
    mPresetManager->getXmlForPreset(presetBody);
    preset.addChildElement(presetBody);
    copyXmlToBinary(preset, destData);
}

void KadenzeAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    std::unique_ptr<XmlElement> xmlState;
    xmlState.reset(getXmlFromBinary(data, sizeInBytes));
    
    
    if(xmlState != nullptr){
        forEachXmlChildElement(*xmlState, subChild){
            mPresetManager->loadPresetForXml(subChild);
        }
    } else {
        jassertfalse;
    }
}

float KadenzeAudioPluginAudioProcessor::getInputGainMeterLevel(int inChannel)
{
    const float normalizeddB = dBToNormalizedGain(mInputGain[inChannel]->getMeterLevel());
    return normalizeddB;
}

float KadenzeAudioPluginAudioProcessor::getOutputGainMeterLevel(int inChannel)
{
    const float normalizeddB = dBToNormalizedGain(mOutputGain[inChannel]->getMeterLevel());
    return normalizeddB;
}

void KadenzeAudioPluginAudioProcessor::initializeDSP()
{
    for(int i = 0; i < 2; i++){
        mInputGain[i].reset(new KAPGain());
        mDelay[i].reset(new KAPDelay());
        mLfo[i].reset(new KAPLfo());
        mOutputGain[i].reset(new KAPGain());
    }
}

AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for(int i = 0; i < kParameter_TotalNumParameters; i++){
        params.push_back(std::make_unique<AudioParameterFloat>(
                                                               KAPParameterID[i],
                                                               KAPParameterLabel[i],
                                                               NormalisableRange<float>(0.0f, 1.0f),
                                                               0.5f));
    }
    return {params.begin(), params.end()};
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KadenzeAudioPluginAudioProcessor();
}

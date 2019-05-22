/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "KAPGain.h"
#include "KAPDelay.h"
#include "KAPLfo.h"

#include "KAPPresetManager.h"
#include "KAPParameters.h"

//==============================================================================
/**
*/
class KadenzeAudioPluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    KadenzeAudioPluginAudioProcessor();
    ~KadenzeAudioPluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float getInputGainMeterLevel(int inChannel);
    float getOutputGainMeterLevel(int inChannel);
    
    AudioProcessorValueTreeState parameters;
    
    KAPPresetManager* getPresetManager()
    {
        return mPresetManager.get();
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
    
private:
    /** internal */
    void initializeDSP();
    
    /** internal */
    void initializeParameters();
    
    std::unique_ptr<KAPGain> mInputGain[2];
    std::unique_ptr<KAPDelay> mDelay[2];
    std::unique_ptr<KAPLfo> mLfo[2];
    std::unique_ptr<KAPGain> mOutputGain[2];
    
    std::unique_ptr<KAPPresetManager> mPresetManager;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeAudioPluginAudioProcessor)
};

/*
  ==============================================================================

    KAPFxPanel.cpp
    Created: 9 May 2019 7:33:00am
    Author:  accraze

  ==============================================================================
*/

#include "KAPFxPanel.h"
#include "KAPParameters.h"

KAPFxPanel::KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
//  mStyle(kKAPFxPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
    setFxPanelStyle(kKAPFxPanelStyle_Delay);
}

KAPFxPanel::~KAPFxPanel()
{
    
}

void KAPFxPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);
    
    switch(mStyle)
    {
        case (kKAPFxPanelStyle_Delay): {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
            
        case (kKAPFxPanelStyle_Chorus): {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
        } break;
            
        default:
        case (kKAPFxPanelStyle_TotalNumStyles): {
            g.drawFittedText("NO", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            jassertfalse;
        } break;
    }
    
}

void KAPFxPanel::setFxPanelStyle(KAPFxPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mSliders.clear();
    
    const int slider_size = 56;
    int x = 130;
    int y = (getHeight()*0.5) - (slider_size*0.5);
    
    switch(mStyle)
    {
        case (kKAPFxPanelStyle_Delay): {
            KAPParameterSlider* time = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_DelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* feedback = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_DelayFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);

        } break;
            
        case (kKAPFxPanelStyle_Chorus): {
            
            KAPParameterSlider* rate = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_ModulationRate]);
            rate->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* depth = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_ModulationDepth]);
            depth->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            x = x + (slider_size * 2);
            
            KAPParameterSlider* wetdry = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[kParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);

        } break;
            
        default:
        case (kKAPFxPanelStyle_TotalNumStyles): {
            jassertfalse;
        } break;
    }
}

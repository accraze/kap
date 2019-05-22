/*
  ==============================================================================

    KAPVUMeter.h
    Created: 21 May 2019 9:45:38am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVUMeter
:    public Component,
     public Timer
{
public:
    KAPVUMeter(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPVUMeter();
    
    void paint(Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    
    int mParameterID;
    
    float mCh0Level;
    float mCh1Level;
    
    KadenzeAudioPluginAudioProcessor* mProcessor;
};

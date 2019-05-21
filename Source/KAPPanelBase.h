/*
  ==============================================================================

    KAPPanelBase.h
    Created: 9 May 2019 7:31:34am
    Author:  accraze

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase
: public Component
{
public:
    KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();
    
    void mouseEnter(const MouseEvent& event) override;
    void mouseExit(const MouseEvent& event) override;
    
    void paint (Graphics &g) override;
    
protected:
    KadenzeAudioPluginAudioProcessor* mProcessor;
};

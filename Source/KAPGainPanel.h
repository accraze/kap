/*
  ==============================================================================

    KAPGainPanel.h
    Created: 9 May 2019 7:33:26am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

class KAPGainPanel
:    public KAPPanelBase
{
public:
    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();
    
    void paint(Graphics& g) override;
    
    void setParameterID(int inParameterID);
private:
    std::unique_ptr<KAPParameterSlider> mSlider;
};

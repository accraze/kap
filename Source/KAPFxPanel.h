/*
  ==============================================================================

    KAPFxPanel.h
    Created: 9 May 2019 7:33:00am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

enum KAPFxPanelStyle
{
    kKAPFxPanelStyle_Delay,
    kKAPFxPanelStyle_Chorus,
    kKAPFxPanelStyle_TotalNumStyles
};

class KAPFxPanel
:   public KAPPanelBase
{
public:
    KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPFxPanel();
    
    void setFxPanelStyle(KAPFxPanelStyle inStyle);
    void paint(Graphics& g) override;
private:
    KAPFxPanelStyle mStyle;
    
    OwnedArray<KAPParameterSlider> mSliders;
};

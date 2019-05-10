/*
  ==============================================================================

    KAPGainPanel.h
    Created: 9 May 2019 7:33:26am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPGainPanel
:    public KAPPanelBase
{
public:
    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();
private:
};

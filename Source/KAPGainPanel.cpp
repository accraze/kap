/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 9 May 2019 7:33:26am
    Author:  accraze

  ==============================================================================
*/

#include "KAPGainPanel.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:    KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

KAPGainPanel::~KAPGainPanel()
{
    
}

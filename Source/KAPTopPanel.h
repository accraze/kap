/*
  ==============================================================================

    KAPTopPanel.h
    Created: 9 May 2019 7:33:53am
    Author:  accraze

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

class KAPTopPanel
: public KAPPanelBase
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint (Graphics &g) override;
    
protected:
    KadenzeAudioPluginAudioProcessor* mProcessor;
};

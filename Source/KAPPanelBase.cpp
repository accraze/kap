/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 9 May 2019 7:31:34am
    Author:  accraze

  ==============================================================================
*/

#include "KAPPanelBase.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}

KAPPanelBase::~KAPPanelBase()
{
    
}

void KAPPanelBase::paint (Graphics &g)
{
    g.setColour(Colours::seagreen);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);
}

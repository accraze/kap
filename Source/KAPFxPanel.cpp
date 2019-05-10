/*
  ==============================================================================

    KAPFxPanel.cpp
    Created: 9 May 2019 7:33:00am
    Author:  accraze

  ==============================================================================
*/

#include "KAPFxPanel.h"

KAPFxPanel::KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor),
  mStyle(kKAPFxPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

KAPFxPanel::~KAPFxPanel()
{
    
}

void KAPFxPanel::setFxPanelStyle(KAPFxPanelStyle inStyle)
{
    mStyle = inStyle;
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

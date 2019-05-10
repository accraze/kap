/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 9 May 2019 7:32:33am
    Author:  accraze

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"

KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}

KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{
    
}

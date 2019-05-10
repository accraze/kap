/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 9 May 2019 7:32:17am
    Author:  accraze

  ==============================================================================
*/

#include "KAPCenterPanel.h"

KAPCenterPanel::KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:  KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar.reset(new KAPCenterPanelMenuBar(inProcessor));
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mMenuBar);
    
    mFxPanel.reset(new KAPFxPanel(inProcessor));
    mFxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(*mFxPanel);
}

KAPCenterPanel::~KAPCenterPanel()
{
    
}

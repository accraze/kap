/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 9 May 2019 7:32:17am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel
:  public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanel();
private:
    std::unique_ptr<KAPCenterPanelMenuBar> mMenuBar;
    std::unique_ptr<KAPFxPanel> mFxPanel;
};

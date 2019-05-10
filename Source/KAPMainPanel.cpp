/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 9 May 2019 7:31:59am
    Author:  accraze

  ==============================================================================
*/

#include "KAPMainPanel.h"

KAPMainPanel::KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:    KAPPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel.reset(new KAPTopPanel(inProcessor));
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(*mTopPanel);
    
    mInputGainPanel.reset(new KAPGainPanel(inProcessor));
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mInputGainPanel);
    
    mOutputGainPanel.reset(new KAPGainPanel(inProcessor));
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mOutputGainPanel);
    
    mCenterPanel.reset(new KAPCenterPanel(inProcessor));
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(*mCenterPanel);
}

KAPMainPanel::~KAPMainPanel()
{
    
}

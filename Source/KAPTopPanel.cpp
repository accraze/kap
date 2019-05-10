/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 9 May 2019 7:33:53am
    Author:  accraze

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:  KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

KAPTopPanel::~KAPTopPanel()
{
    
}

void KAPTopPanel::paint (Graphics &g)
{
    KAPPanelBase::paint(g);
    
    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}

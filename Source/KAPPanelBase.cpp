/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 9 May 2019 7:31:34am
    Author:  accraze

  ==============================================================================
*/

#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}

KAPPanelBase::~KAPPanelBase()
{
    
}

void KAPPanelBase::mouseEnter(const MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::mouseExit(const MouseEvent& event)
{
    repaint();
}

void KAPPanelBase::paint (Graphics &g)
{
    if(isMouseOver(true)){
        const Colour hoverColour = Colour(Colours::black).withAlpha(0.4f);
        
        g.setColour(hoverColour);
        g.fillAll();
    }
}


/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 9 May 2019 7:33:26am
    Author:  accraze

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"
#include "KAPHelperFunctions.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:    KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

KAPGainPanel::~KAPGainPanel()
{
    
}

void KAPGainPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);
    
    if(mSlider){
        paintComponentLabel(g, &*mSlider);
    }
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider.reset(new KAPParameterSlider(mProcessor->parameters, KAPParameterID[inParameterID], KAPParameterLabel[inParameterID]));
    const int slider_size = 54;
    
    mSlider->setBounds((getWidth() * 0.5) - (slider_size *0.5),
                       (getHeight() * 0.5) - (slider_size * 0.5),
                       slider_size,
                       slider_size
                       );
    
    addAndMakeVisible(*mSlider);
}

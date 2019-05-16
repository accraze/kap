/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 9 May 2019 7:15:44pm
    Author:  accraze

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterId)
: juce::Slider(parameterId)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterId, *this));
}
KAPParameterSlider::~KAPParameterSlider()
{
    
}

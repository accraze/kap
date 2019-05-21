/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 9 May 2019 7:15:44pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterSlider
:    public Slider
{
public:
    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl,
                       const String& parameterId,
                       const String& parameterLabel);
    ~KAPParameterSlider();
private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider);
};

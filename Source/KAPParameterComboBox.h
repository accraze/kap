/*
  ==============================================================================

    KAPParameterComboBox.h
    Created: 9 May 2019 7:15:56pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterComboBox
:    public ComboBox
{
public:
    KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterId);
    ~KAPParameterComboBox();
private:
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox);
};

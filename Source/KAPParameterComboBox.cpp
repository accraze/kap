/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 9 May 2019 7:15:56pm
    Author:  accraze

  ==============================================================================
*/

#include "KAPParameterComboBox.h"

KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterId)
: juce::ComboBox(parameterId)
{
    mAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterId, *this));
}

KAPParameterComboBox::~KAPParameterComboBox()
{
}

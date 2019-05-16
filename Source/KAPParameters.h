/*
  ==============================================================================

    KAPParameters.h
    Created: 9 May 2019 5:43:04pm
    Author:  accraze

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,    // chorus or delay?
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_TotalNumParameters,
};

static String KAPParameterID [kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth",
};

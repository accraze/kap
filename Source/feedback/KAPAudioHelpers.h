/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 8 May 2019 8:10:58am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.002

const int maxBufferDelaySize = 192000;

const double kPi = 3.14159265359;
const double k2Pi = 6.28318530718;

inline float kap_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}

inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}

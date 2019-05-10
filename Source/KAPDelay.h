/*
  ==============================================================================

    KAPDelay.h
    Created: 8 May 2019 8:14:18am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPDelay
{
public:
    KAPDelay();
    ~KAPDelay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void  process(float* inAudio,
                  float inTime,
                  float inFeedback,
                  float inWetDry,
                  float* inModulationBUffer,
                  float* outAudio,
                  int inNumSamplesToRender);
    
private:
    /** internal */
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
};

/*
  ==============================================================================

    KAPLfo.h
    Created: 8 May 2019 8:11:52am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate, float inDepth, int inNumSamples);
    
    float* getBuffer();
    
private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferDelaySize];
};

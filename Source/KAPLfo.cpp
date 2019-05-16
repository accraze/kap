/*
  ==============================================================================

    KAPLfo.cpp
    Created: 8 May 2019 8:11:52am
    Author:  accraze

  ==============================================================================
*/

#include "KAPLfo.h"
#include "JuceHeader.h"

KAPLfo::KAPLfo()
{
    reset();
}

KAPLfo::~KAPLfo()
{
    
}

void KAPLfo::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferDelaySize);
}

void KAPLfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPLfo::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for(int i = 0; i < inNumSamples; i++){
        mPhase = mPhase + (rate/ mSampleRate);
        
        if(mPhase>1.0f){
            mPhase = mPhase - 1.0f;
        }
        
        const float lfoPostion = sinf(mPhase * k2Pi) * inDepth;
        mBuffer[i] = lfoPostion;
    }
}

float* KAPLfo::getBuffer()
{
    return mBuffer;
}

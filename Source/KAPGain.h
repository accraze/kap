/*
  ==============================================================================

    KAPGain.h
    Created: 8 May 2019 8:12:11am
    Author:  accraze

  ==============================================================================
*/

#pragma once

class KAPGain
{
public:
    KAPGain();
    ~KAPGain();
    
    void process(float* inAudio,
                 float inGain,
                 float* outAudio,
                 int inNumSamplesToRender);
private:
};

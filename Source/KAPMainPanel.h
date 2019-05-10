/*
  ==============================================================================

    KAPMainPanel.h
    Created: 9 May 2019 7:31:59am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
: public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPMainPanel();
private:
    
    std::unique_ptr<KAPTopPanel> mTopPanel;
    std::unique_ptr<KAPGainPanel> mInputGainPanel;
    std::unique_ptr<KAPGainPanel> mOutputGainPanel;
    std::unique_ptr<KAPCenterPanel> mCenterPanel;
};

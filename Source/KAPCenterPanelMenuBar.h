/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 9 May 2019 7:32:33am
    Author:  accraze

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar
:  public KAPPanelBase
{
public:
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();
    
    void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);
private:
    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;
};

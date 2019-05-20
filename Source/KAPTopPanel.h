/*
  ==============================================================================

    KAPTopPanel.h
    Created: 9 May 2019 7:33:53am
    Author:  accraze

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

class KAPTopPanel
: public KAPPanelBase,
  public Button::Listener,
  public ComboBox::Listener
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint (Graphics &g) override;
    
    void buttonClicked(Button* b) override;
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
private:
    
    void displaySaveAsPopup();
    
    void updatePresetComboBox();
    
    std::unique_ptr<ComboBox> mPresetDisplay;
    
    std::unique_ptr<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
    
    KadenzeAudioPluginAudioProcessor* mProcessor;
};

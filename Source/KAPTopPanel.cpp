/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 9 May 2019 7:33:53am
    Author:  accraze

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
:  KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPreset.reset(new TextButton());
    mNewPreset->setButtonText("NEW");
    mNewPreset->setBounds(button_x, button_y, button_w, button_h);
    mNewPreset->addListener(this);
    addAndMakeVisible(*mNewPreset);
    button_x = button_x + button_w;
    
    mSavePreset.reset(new TextButton());
    mSavePreset->setButtonText("SAVE");
    mSavePreset->setBounds(button_x, button_y, button_w, button_h);
    mSavePreset->addListener(this);
    addAndMakeVisible(*mSavePreset);
    button_x = button_x + button_w;
    
    mSaveAsPreset.reset(new TextButton());
    mSaveAsPreset->setButtonText("SAVE AS");
    mSaveAsPreset->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPreset->addListener(this);
    addAndMakeVisible(*mSaveAsPreset);
    button_x = button_x + button_w;
    
    const int comboBox_w = 200;
    const int comboBox_x = TOP_PANEL_WIDTH*0.5 - comboBox_w * 0.5;
    
    mPresetDisplay.reset(new ComboBox());
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mPresetDisplay->addListener(this);
    addAndMakeVisible(*mPresetDisplay);
    
    //updatePresetComboBox();
}

KAPTopPanel::~KAPTopPanel()
{
    
}

void KAPTopPanel::paint (Graphics &g)
{
    KAPPanelBase::paint(g);
    
    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}


void KAPTopPanel::buttonClicked(Button* b)
{
    KAPPresetManager* presetManager = mProcessor->getPresetManager();
    
    if( b == &*mNewPreset ){
        presetManager->createNewPreset();
        updatePresetComboBox();
    }
    else if (b == &*mSavePreset){
        presetManager->savePreset();
    }
    else if (b == &*mSaveAsPreset){
        displaySaveAsPopup();
    }
    
}

void KAPTopPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if(&*comboBoxThatHasChanged == &*mPresetDisplay)
    {
        KAPPresetManager* presetManager = &*mProcessor->getPresetManager();
        
        const int index = mPresetDisplay->getSelectedItemIndex();
        presetManager->loadPreset(index);
    }
}

void KAPTopPanel::displaySaveAsPopup()
{
    KAPPresetManager* presetManager = &*mProcessor->getPresetManager();
    
    String currentPresetName = presetManager->getCurrentPresetName();
    AlertWindow window ("Save As", "Please Enter a Name for your Preset", AlertWindow::NoIcon);
    
    window.centreAroundComponent(this, getWidth(), getHeight());
    
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);
    
    if(window.runModalLoop()){
        String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);
        
        updatePresetComboBox();
    }
    
    
}

void KAPTopPanel::updatePresetComboBox()
{
    KAPPresetManager* presetManager = &*mProcessor->getPresetManager();
    String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(dontSendNotification);
    
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
    
    const int numPreset = presetManager->getNumberOfPresets();
    
    for(int i = 0; i< numPreset; i++){
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i+1));
    }
    
}

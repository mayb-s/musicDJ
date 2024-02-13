/*
  ==============================================================================

    DeckGUI.cpp
    Created: 23 Feb 2023 7:55:00pm
    
  ==============================================================================
*/

#include "DeckGUI.h"

//HW week 16
DeckGUI::DeckGUI(DJAudioPlayer* _player,
    juce::AudioFormatManager& formatManagerToUse,
    juce::AudioThumbnailCache& cacheToUse)
    : player(_player),
    waveformDisplay(formatManagerToUse, cacheToUse),
    position(0.0),
    playclicked(false),
    posSliderChanged(false)
{

    addAndMakeVisible(waveformDisplay);
    addAndMakeVisible(posSlider);
    addAndMakeVisible(posSliderChanger);
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(volSlider);

    addAndMakeVisible(turntable);
    addAndMakeVisible(speedKnob);
    
    playButton.addListener(this);
    stopButton.addListener(this);
    volSlider.addListener(this);
    posSlider.addListener(this);
    posSliderChanger.addListener(this);


    volSlider.setRange(0.0, 1,0.01 );
    posSlider.setRange(0.0,3600,.1);
    posSliderChanger.setRange(0.0, 1);

    //styling sliders
    volSlider.setSliderStyle(juce::Slider::LinearVertical);
    volSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    volSlider.setTextValueSuffix(" Vol");

    posSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 20);
    posSlider.setColour(juce::Slider::thumbColourId, juce::Colour{ 0,0,0 }.withAlpha(0.0f));
    posSlider.setColour(juce::Slider::trackColourId, juce::Colour{ 0,0,0 }.withAlpha(0.0f));
    posSlider.setColour(juce::Slider::backgroundColourId, juce::Colour{ 0,0,0 }.withAlpha(0.0f));
    posSlider.setTextValueSuffix(" Seconds");

    posSliderChanger.setTextBoxStyle(juce::Slider::NoTextBox, false,0,0);
    posSliderChanger.setAlpha(0.0f);
    
    startTimer(500);

}
DeckGUI::~DeckGUI()
{
    //HW week 18
    stopTimer();
}

void DeckGUI::paint(juce::Graphics& g)
{
    juce::Rectangle<float> deckBounds = getLocalBounds().toFloat();
   
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colour{76,0,153});
    g.drawRect(getLocalBounds(), 1);
    g.setColour(juce::Colours::white);
    
    if (playclicked)
    {
        posSlider.setValue(position);
    }
    else { 
        posSlider.setValue(0);
    }

        
}

void DeckGUI::resized()
{
    double rowH = getHeight() / 10;
    double columnW = getWidth() / 10;

    waveformDisplay.setBounds(0, 0, columnW*10, rowH*2);
    posSlider.setBounds(0, rowH/5, columnW*10, rowH*2);
    posSliderChanger.setBounds(0, rowH/5, columnW*10, rowH*2);
    volSlider.setBounds(0, rowH*2, columnW*1.5, rowH*6);
   
    
    float ComponentWidth = 280;
    float ComponentHeight = 280;
    float originalAspectRatio = 1.0f;
    float viewportAspectRatio = columnW/ float(rowH);
    float scaleFactor = 1.0f;
    if (viewportAspectRatio > originalAspectRatio)
    {
        scaleFactor = (rowH * 7) / (float)ComponentHeight * 0.75;
       
    }
    else if (viewportAspectRatio < originalAspectRatio)
    {
        scaleFactor = (columnW * 7) / (float)ComponentWidth * 0.75;
       
    }

    turntable.setBounds(columnW*2.7, rowH*2.3,
        (280)*scaleFactor, 280*scaleFactor);
   

    ComponentWidth = 80;
    ComponentHeight = 96;
    originalAspectRatio = ComponentWidth/ ComponentHeight;
    viewportAspectRatio = (columnW * 2 )/ (rowH * 2.4);
    scaleFactor = 1.0f;
    if (viewportAspectRatio > originalAspectRatio)
    {
        scaleFactor = (rowH * 2.4) / (float)ComponentHeight;
    }
    else if (viewportAspectRatio < originalAspectRatio)
    {
        scaleFactor = (columnW * 2) / (float)ComponentWidth;
    }

    speedKnob.setBounds(columnW, rowH * 2, 80*scaleFactor, 96*scaleFactor);


    playButton.setBounds(0, rowH*9, columnW*2, rowH);
    stopButton.setBounds(columnW*2, rowH*9, columnW*2, rowH);
    
   
}
void DeckGUI::buttonClicked(juce::Button* button)
{
    DBG("button was clicked in deckgui" );

    if (button == &playButton)
    {
        
        DBG("PLAY WAS CLICKED in deckgui");
        player->play();
        playclicked = true;
        turntable.Start(true);
    
           
    }
    if (button == &stopButton)
    {
        
        DBG("STOP WAS CLICKED in dedckgui");
        player->stop();
        turntable.Start(false);
      
    }

}

void DeckGUI::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &volSlider)
    {
        player->setGain(slider->getValue());
    }
    if (slider == &posSliderChanger)
    {
        player->setPositionRelative(slider->getValue());
        
    }
}

//HW week 18
void DeckGUI::timerCallback()
{
    waveformDisplay.setPositionRelative(player->getPositionRelative());
    turntable.setPosition(player->getPosition());
    setPosition(player->getPosition());
    
}

//week 20
void DeckGUI::loadWaveform(std::string filepath)
{
    DBG("loadWaveform was CALLED IN DECKGUI");
    waveformDisplay.loadURL(juce::URL{ juce::File{filepath} });
   
}


void DeckGUI::setPosition(double pos)
{
    DBG("setPosition was CALLED IN DECKGUI");
    
    if (pos != position)
    {
        position = pos;
        repaint();
    }

}
std::string DeckGUI::getData(std::string name, std::string length)
{
    // name of song for display to draw on deck
    return std::string();
}
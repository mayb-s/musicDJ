/*
  ==============================================================================

    Knob.cpp
    Created: 11 Mar 2023 12:34:12am
   

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Knob.h"

//==============================================================================
Knob::Knob(DJAudioPlayer* _player)
    :player(_player)
{

    addAndMakeVisible(Speedknob);
    Speedknob.addListener(this);
    Speedknob.setRange(0.0, 2, 0.01);
    Speedknob.setSliderStyle(juce::Slider::Rotary);
    Speedknob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 15);
    Speedknob.setTextValueSuffix("xSpeed");

}

Knob::~Knob()
{
}

void Knob::paint (juce::Graphics& g)
{
    

    g.setColour(juce::Colours::darkgrey);
    juce::Rectangle<float> center = getLocalBounds().toFloat();
    float centerRatioFix = center.getWidth() / center.getHeight();
    center.setHeight(center.getHeight()*centerRatioFix);
    juce::Rectangle<float> scaleDown = center.reduced(15.0f);
    g.fillEllipse(scaleDown); 

    

}

void Knob::resized()
{
    Speedknob.setBounds(0, 0, getWidth(), getHeight());
}

void Knob::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &Speedknob)
    {
        player->setSpeed(slider->getValue());
    }

}

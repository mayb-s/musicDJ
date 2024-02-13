/*
  ==============================================================================

    Turntable.cpp
    Created: 10 Mar 2023 11:01:41pm

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Turntable.h"

//==============================================================================
Turntable::Turntable(DJAudioPlayer* _player)
    :position(0),playClicked(false),player(_player)
{

    addAndMakeVisible(slider1);
    slider1.addListener(this);
    slider1.setRange(0.0, 500,0.001);
    slider1.setSliderStyle(juce::Slider::Rotary);
    slider1.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider1.setRotaryParameters(0, 360, false);
    slider1.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider1.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider1.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider2);
    slider2.addListener(this);
    slider2.setRange(0.0, 500,0.001);
    slider2.setSliderStyle(juce::Slider::Rotary);
    slider2.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider2.setRotaryParameters(0, 360, false);
    slider2.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider2.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider2.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider3);
    slider3.addListener(this);
    slider3.setRange(0.0, 500,0.001);
    slider3.setSliderStyle(juce::Slider::Rotary);
    slider3.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider3.setRotaryParameters(0, 360, false);
    slider3.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider3.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider3.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider4);
    slider4.addListener(this);
    slider4.setRange(0.0, 500,0.001);
    slider4.setSliderStyle(juce::Slider::Rotary);
    slider4.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider4.setRotaryParameters(0, 360, false);
    slider4.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider4.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider4.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider5);
    slider5.addListener(this);
    slider5.setRange(0.0, 500,0.001);
    slider5.setSliderStyle(juce::Slider::Rotary);
    slider5.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider5.setRotaryParameters(0, 360, false);
    slider5.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider5.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider5.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider6);
    slider6.addListener(this);
    slider6.setRange(0.0, 500,0.001);
    slider6.setSliderStyle(juce::Slider::Rotary);
    slider6.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider6.setRotaryParameters(0, 360, false);
    slider6.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider6.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider6.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider7);
    slider7.addListener(this);
    slider7.setRange(0.0, 500,0.001);
    slider7.setSliderStyle(juce::Slider::Rotary);
    slider7.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider7.setRotaryParameters(0, 360, false);
    slider7.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider7.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider7.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });



    addAndMakeVisible(slider8);
    slider8.addListener(this);
    slider8.setRange(0.0, 500,0.001);
    slider8.setSliderStyle(juce::Slider::Rotary);
    slider8.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider8.setRotaryParameters(0, 360, false);
    slider8.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider8.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider8.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider9);
    slider9.addListener(this);
    slider9.setRange(0.0, 500,0.001);
    slider9.setSliderStyle(juce::Slider::Rotary);
    slider9.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider9.setRotaryParameters(0, 360, false);
    slider9.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider9.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider9.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider10);
    slider10.addListener(this);
    slider10.setRange(0.0, 500,0.001);
    slider10.setSliderStyle(juce::Slider::Rotary);
    slider10.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider10.setRotaryParameters(0, 360, false);
    slider10.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider10.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider10.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider11);
    slider11.addListener(this);
    slider11.setRange(0.0, 500,0.001);
    slider11.setSliderStyle(juce::Slider::Rotary);
    slider11.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider11.setRotaryParameters(0, 360, false);
    slider11.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour{ 7,7,7 });
    slider11.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour{ 7,7,7 });
    slider11.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });


    addAndMakeVisible(slider12);
    slider12.addListener(this);
    slider12.setRange(0.0, 500, 0.001);
    slider12.setSliderStyle(juce::Slider::Rotary);
    slider12.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider12.setRotaryParameters(0, 360, false);
    slider12.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::black);
    slider12.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    slider12.setColour(juce::Slider::thumbColourId, juce::Colour{ 102, 178, 255 });

    addAndMakeVisible(scratcher);
    scratcher.addListener(this);
    scratcher.setRange(0.0, 0.5, .00001);
    scratcher.setSliderStyle(juce::Slider::LinearVertical);
    scratcher.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    scratcher.setAlpha(0.0f);



}

Turntable::~Turntable()
{
}

void Turntable::paint (juce::Graphics& g)
{

     //Draw turntable
    g.setColour(juce::Colour{ 102,0,204 });
    juce::Rectangle<float> tableBounds = getLocalBounds().toFloat();
    g.fillEllipse(tableBounds);

    g.setColour(juce::Colour{ 102, 178, 255 });
    juce::Rectangle<float> recordBounds = tableBounds.reduced(80.0f);
    g.fillEllipse(recordBounds);
    g.setColour(juce::Colours::black);
    
    g.setColour(juce::Colour{ 102,0,204 });
    juce::Rectangle<float> centerBounds = recordBounds.reduced(55.0f);
    g.fillEllipse(centerBounds);

   
   
    if (playClicked)
    {
        slider1.setValue(position);
        slider2.setValue(position);
        slider3.setValue(position);
        slider4.setValue(position);
        slider5.setValue(position);
        slider6.setValue(position);
        slider7.setValue(position);
        slider8.setValue(position);
        slider9.setValue(position);
        slider10.setValue(position);
        slider11.setValue(position);
        slider12.setValue(position);

    }
    else {
        slider1.setValue(0);
        slider2.setValue(0);
        slider3.setValue(0);
        slider4.setValue(0);
        slider5.setValue(0);
        slider6.setValue(0);
        slider7.setValue(0);
        slider8.setValue(0);
        slider9.setValue(0);
        slider10.setValue(0);
        slider11.setValue(0);
        slider12.setValue(0);

    }
   
}

void Turntable::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    int w = getWidth() / 40;
    int h = getHeight() / 40;
 

    slider1.setBounds(w * 1.5, h * 1.5, getWidth() - (w * 3), getHeight() - (h * 3));
    slider2.setBounds(w * 2.5, h * 2.5, getWidth() - (w * 5), getHeight() - (h * 5));
    slider3.setBounds(w * 3.5, h * 3.5, getWidth() - (w * 7), getHeight() - (h * 7));
    slider4.setBounds(w * 4.5, h * 4.5, getWidth() - (w * 9), getHeight() - (h * 9));
    slider5.setBounds(w * 5.5, h * 5.5, getWidth() - (w * 11), getHeight() - (h * 11));
    slider6.setBounds(w * 6.5, h * 6.5, getWidth() - (w * 13), getHeight() - (h * 13));
    slider7.setBounds(w * 7.5, h * 7.5, getWidth() - (w * 15), getHeight() - (h * 15));
    slider8.setBounds(w * 8.5, h * 8.5, getWidth() - (w * 17), getHeight() - (h * 17));
    slider9.setBounds(w * 9.5, h * 9.5, getWidth() - (w * 19), getHeight() - (h * 19));
    slider10.setBounds(w * 10.5, h * 10.5, getWidth() - (w * 21), getHeight() - (h * 21));
    slider11.setBounds(w * 11.5, h * 11.5, getWidth() - (w * 23), getHeight() - (h * 23));
    slider12.setBounds(w * 12.5, h * 12.5, getWidth() - (w * 25), getHeight() - (h * 25));

    scratcher.setBounds(w-90, h, 300, getHeight());

}


void Turntable::setPosition(double pos)
{
    DBG("setPosition was CALLED IN Turntable");

    if (pos != position)
    {
        position = pos;
        repaint();
    }

}

void Turntable::sliderValueChanged(juce::Slider* _slider)
{

    if (_slider == &scratcher)
    {
        player->setPosition(_slider->getValue());

    }

}

bool Turntable::Start(bool)
{
    playClicked = true;
    return playClicked;
}
bool Turntable::Stop(bool)
{
    playClicked = false;
    return playClicked;
}

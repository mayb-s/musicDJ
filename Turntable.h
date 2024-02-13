/*
  ==============================================================================

    Turntable.h
    Created: 10 Mar 2023 11:01:41pm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"

//==============================================================================
class Turntable : public juce::Component,
    public juce::Slider::Listener
{
public:
    Turntable(DJAudioPlayer* player);
    ~Turntable() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setPosition(double pos);

    void sliderValueChanged(juce::Slider* slider) override;
   
    bool Start(bool);

    bool Stop(bool);

private:

    juce::Slider slider1;
    juce::Slider slider2;
    juce::Slider slider3;
    juce::Slider slider4;
    juce::Slider slider5;
    juce::Slider slider6;
    juce::Slider slider7;
    juce::Slider slider8;
    juce::Slider slider9;
    juce::Slider slider10;
    juce::Slider slider11;
    juce::Slider slider12;

    juce::Slider scratcher;

    double position;
    bool playClicked;

    DJAudioPlayer* player;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Turntable)
};

/*
  ==============================================================================

    Knob.h
    Created: 11 Mar 2023 12:34:12am
    

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"
//==============================================================================
class Knob  : public juce::Component,
    public juce::Slider::Listener
            
{
public:
    Knob(DJAudioPlayer* player);
    ~Knob() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;


private:


    juce::Slider Speedknob;
  

    DJAudioPlayer* player;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Knob)
};

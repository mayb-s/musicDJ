/*
  ==============================================================================

    WaveformDisplay.h
    Created: 24 Feb 2023 4:45:13pm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//HW week 17
class WaveformDisplay : public juce::Component,
                        public juce::ChangeListener
{
public:
    WaveformDisplay(juce::AudioFormatManager& formatManagerToUse,
        juce::AudioThumbnailCache& cacheToUse);
    ~WaveformDisplay();
    void paint(juce::Graphics&) override;
    void resized() override;

    //HW week 17 part 3
    void loadURL(juce::URL audioURL);

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    //HW week 18
    /** set the relative position of the play head*/
    void setPositionRelative(double pos);


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformDisplay)

    //HW week 17 part 2
    juce::AudioThumbnail audioThumbnail;

    //HW week 17 part 3
    bool fileLoaded;

    //HW week 18
    double position;

};

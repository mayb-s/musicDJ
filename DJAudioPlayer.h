/*
  ==============================================================================

    DJAudioPlayer.h
    Created: 22 Feb 2023 9:24:01pm

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"


//==============================================================================
class DJAudioPlayer : public juce::AudioSource,
                      public juce::Component
{

public:
    //HW work 17 part 3
    DJAudioPlayer(juce::AudioFormatManager& _formatManager,
                  juce::AudioThumbnailCache& cacheToUse);

    ~DJAudioPlayer();
    /** loads the file */
    void loadURL(juce::URL audioURL);
    /** starts playing the file */
    void play();
    /** stops playing the file */
    void stop();
    /** ... */
    void setPosition(double posInSecs);
    /** ... */
    void setGain(double gain);

    //HW week 15
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void setPositionRelative(double pos);

    void setSpeed(double ratio);

    //HW week 18
    /** get the relative position of the play head */
    double getPositionRelative();
    double getPosition();

    double getLength();


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DJAudioPlayer)
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;
    juce::ResamplingAudioSource resampleSource{ &transportSource, false, 2 };

    //HW week 17 part 3
    juce::AudioFormatManager& formatManager;


};

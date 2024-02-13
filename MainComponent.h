/*
  ==============================================================================

    DeckGUI.h
    Created: 22 Feb 2023 7:55:00pm

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
#include "MusicLibrary.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
//Homework week 13 part 2
class MainComponent : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;


    

private:
    //==============================================================================
    // Your private member variables go here...

    //HW week 17 part 2
    juce::AudioFormatManager formatManager;
    juce::AudioThumbnailCache thumbnailCache{100};
    juce::MixerAudioSource mixerSource;

    
    //HW week 17 part 3
    DJAudioPlayer player1{ formatManager, thumbnailCache};
    DJAudioPlayer player2{ formatManager, thumbnailCache};
    
  
    //HW week 19
    DeckGUI deck1{ &player1, formatManager, thumbnailCache};
    DeckGUI deck2{ &player2, formatManager, thumbnailCache};

    //week 20
    MusicLibrary libraryComponent{ &player1,&player2, &deck1, &deck2,
                                    formatManager, thumbnailCache };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)


};

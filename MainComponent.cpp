/*
  ==============================================================================

    DeckGUI.h
    Created: 22 Feb 2023 7:55:00pm

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize(800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio)
        && !juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request(juce::RuntimePermissions::recordAudio,
            [&](bool granted) { if (granted)  setAudioChannels(2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels(0, 2);
    }

    //HW week 16
    addAndMakeVisible(deck1);
    addAndMakeVisible(deck2);

    //HW week 17 part 2
    formatManager.registerBasicFormats();


    //week 20
    addAndMakeVisible(libraryComponent);


}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================

//HW week 14
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.
    
    /////////////////////////////////////////
    player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    player2.prepareToPlay(samplesPerBlockExpected, sampleRate);
//-------------------------------------------------------------------------
    // note that this will call prepareToPlay
    // automatically on the two players
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);

//hw week 16
    mixerSource.addInputSource(&player1, false);
    mixerSource.addInputSource(&player2, false);

    

    std::cout << "prepare to play is called" << std::endl;

}

//HW week 14
void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!
 
    //HW week 16
    mixerSource.getNextAudioBlock(bufferToFill);

}

//HW week 14 part 2
void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    //hw week 16
    player1.releaseResources();
    player2.releaseResources();
    mixerSource.releaseResources();
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
    g.fillAll(juce::Colour{ 178, 102, 255 });

}

//HW week 16
void MainComponent::resized()
{
    int deckHeight = getHeight() - 200;
    deck1.setBounds(0, 0, getWidth() / 2, deckHeight);
    deck2.setBounds(getWidth() / 2, 0, getWidth() / 2, deckHeight);

    
    //week 20
    libraryComponent.setBounds(0, getHeight()-200, 
        getWidth(), getHeight()-deckHeight);

}


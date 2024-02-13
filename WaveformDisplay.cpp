/*
  ==============================================================================

    WaveformDisplay.cpp
    Created: 24 Feb 2023 4:45:13pm


  ==============================================================================
*/

#include "WaveformDisplay.h"

//==============================================================================

//HW week 17 part 2
WaveformDisplay::WaveformDisplay(juce::AudioFormatManager& formatManagerToUse,
    juce::AudioThumbnailCache& cacheToUse)
    : audioThumbnail(1000, formatManagerToUse, cacheToUse),
    //HW week 17 part 3
    fileLoaded(false),
    //HW week 18
    position(0)
{
    //HW week 17 part 3
    audioThumbnail.addChangeListener(this);
}

WaveformDisplay::~WaveformDisplay()
{
}

void WaveformDisplay::paint(juce::Graphics& g)
{

    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId)); // clear the background
    
    g.fillAll(juce::Colour{51,0,102 });
    g.drawRect(getLocalBounds(), 1); // draw an outline around the component
    
    g.setColour(juce::Colour{102, 178, 255});
   
    //HW week 17 part 3
    if (fileLoaded)
    {
        audioThumbnail.drawChannel(g, getLocalBounds(), 0, audioThumbnail.getTotalLength(), 0, 1.0);
       // g.setColour(juce::Colour{229,204,255});
        g.setColour(juce::Colours::lightgreen);
        g.drawRect(position * getWidth(), 0, getWidth() / 40, getHeight());
    }
    else
    {
        // put the original paint code here
        g.setFont(20.0f);
        g.drawText("File not loaded...", getLocalBounds(),
            juce::Justification::centred, true); // draw some placeholder text

    }

}

void WaveformDisplay::resized()
{
}

//HW week 17 part 3
void WaveformDisplay::loadURL(juce::URL audioURL)
{
    audioThumbnail.clear();
    fileLoaded = audioThumbnail.setSource(new juce::URLInputSource(audioURL));
}

//HW week 17 part 3
void WaveformDisplay::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    repaint();
}

//HW week 18
void WaveformDisplay::setPositionRelative(double pos)
{
    if (pos != position)
    {
        position = pos;
        repaint();
    }

}


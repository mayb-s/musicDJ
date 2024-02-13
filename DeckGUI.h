/*
  ==============================================================================

	DeckGUI.h
	Created: 23 Feb 2023 7:55:00pm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"
#include "WaveformDisplay.h"
#include "Turntable.h"
#include "Knob.h"
//==============================================================================

//HW week 16
class DeckGUI : public juce::Component,
	public juce::Button::Listener,
	public juce::Slider::Listener,
	public juce::Timer
{
public:

	//HW week 17 part 2
	DeckGUI(DJAudioPlayer* player,
		juce::AudioFormatManager& formatManagerToUse,
		juce::AudioThumbnailCache& cacheToUse);
	
	~DeckGUI();

	void paint(juce::Graphics&g) override;
	
	void resized() override;

	/** implement Button::Listener */
	void buttonClicked(juce::Button*) override;
	/** implement Slider::Listener */
	void sliderValueChanged(juce::Slider * slider) override;
	
	//HW week 18
	void timerCallback() override;

	//week 20
	void loadWaveform(std::string filepath);

	void setPosition(double pos);
	
	std::string getData(std::string name,std::string length);
	

private:
	
	juce::TextButton playButton{ "PLAY" };
	juce::TextButton stopButton{ "STOP" };
	
	juce::Slider volSlider{"Volume"};
	juce::Slider posSlider;
	juce::Slider posSliderChanger;
	juce::FileChooser fChooser{ "Select a file..." };
	
	DJAudioPlayer* player;

	//HW week 17
	WaveformDisplay waveformDisplay;

	Turntable turntable{player};

	Knob speedKnob{ player };

	double position;
	bool playclicked;
	bool posSliderChanged;



	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckGUI)

};



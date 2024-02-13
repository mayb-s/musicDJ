/*
  ==============================================================================

    PlaylistComponent.h
    Created: 24 Feb 2023 9:11:00pm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


//==============================================================================

//HW week 19
class PlaylistComponent  : public juce::Component,
                           public juce::TableListBoxModel,
                           public juce::Button::Listener
    

{
public:
    PlaylistComponent();
    ~PlaylistComponent() override;

    void paint(juce::Graphics& g) override;
    
    void resized() override;

    int getNumRows() override;
    void paintRowBackground(juce::Graphics&g,
        int rowNumber,
        int width,
        int height,
        bool rowIsSelected) override;
    void paintCell(juce::Graphics&g,
        int rowNumber,
        int columnId,
        int width,
        int height,
        bool rowIsSelected) override;


    Component* refreshComponentForCell(int rowNumber,
        int columnId,
        bool isRowSelected,
        Component* existingComponentToUpdate) override;

    void buttonClicked(juce::Button* button) override;

    //week 20
    void addFile(std::string filename,
                 std::string length, 
                 std::string filepath);

    void makeList(int rowNumber, 
                std::string title,
                std::string length);
 
    

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaylistComponent)

    //HW week 19
    juce::TableListBox tableComponent;
    std::vector<std::string> trackTitles;
    std::vector<std::string> trackLengths;

    //week 20
    std::vector<std::vector<std::string>> playlistFiles;

    
    

};

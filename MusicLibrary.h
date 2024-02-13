/*
  ==============================================================================

    MusicLibrary.h
    Created: 26 Feb 2023 6:21:20pm

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "DJAudioPlayer.h"
#include "DeckGUI.h"


//==============================================================================

class MusicLibrary  : public juce::Component,
                      public juce::TableListBoxModel,
                      public juce::Button::Listener,
                      public juce::TextEditor::Listener,
                      public juce::FileDragAndDropTarget
{
public:
    
    MusicLibrary(DJAudioPlayer* player1,
        DJAudioPlayer* player2,
        DeckGUI* deck1,
        DeckGUI* deck2,
        juce::AudioFormatManager& formatManagerToUse,
        juce::AudioThumbnailCache& cacheToUse);
  
    ~MusicLibrary() override;

    void paint (juce::Graphics&g) override;
    
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

    void Deck1(int row);

    void Deck2(int row);

    void loadURL(juce::URL audioURL);

    bool isInterestedInFileDrag(const juce::StringArray& files) override;
    
    void filesDropped(const juce::StringArray& files, int x, int y) override;
   
    void createLibraryFile(const juce::File& file);

    void createList(int rowNumber, 
                   std::string title, 
                   std::string length);
    
    void searchLibrary(std::string input);

    void saveLibrary();
   
    void loadLibrary();
    
    //void deleteFile(int row);

    static std::vector<std::string> tokenize(std::string command, char separator);

  
private:

    juce::AudioFormatManager formatManager;
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;

    std::vector<std::string> titles;
    std::vector<std::string> lengths;
    juce::TableListBox TableList;

    std::vector<std::vector<std::string>> libraryFiles;

    juce::TextButton addButton{ "Add Music" };
    juce::TextButton deleteButton{ "Delete" };
    juce::FileChooser fChooser{ "Select a file..." };
   
    juce::TextEditor searchbox;
    juce::TextButton searchButton{ "Enter" };

    DJAudioPlayer* player1;
    DJAudioPlayer* player2;

    std::vector<std::string> tokens;

    DeckGUI* deck1;
    DeckGUI* deck2;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicLibrary)

};

/*
  ==============================================================================

	MusicLibrary.cpp
	Created: 26 Feb 2023 6:21:20pm


  ==============================================================================
*/

#include <JuceHeader.h>
#include "MusicLibrary.h"
#include <fstream>
#include <iostream>

//==============================================================================

MusicLibrary::MusicLibrary(DJAudioPlayer* _player1,
	DJAudioPlayer* _player2,
	DeckGUI* _deck1,
	DeckGUI* _deck2,
	juce::AudioFormatManager& formatManagerToUse,
	juce::AudioThumbnailCache& cacheToUse)
	: player1(_player1), player2(_player2), 
	deck1(_deck1), deck2(_deck2)
{
   
	addAndMakeVisible(TableList);
	TableList.getHeader().addColumn("", 1, 80);
	TableList.getHeader().addColumn("", 2, 80);
	TableList.getHeader().addColumn("Title", 3, 200);
	TableList.getHeader().addColumn("Length", 4, 200);
	TableList.getHeader().addColumn("", 5, 80);
	TableList.setModel(this);

	addAndMakeVisible(addButton);
	addButton.addListener(this);

	addAndMakeVisible(searchbox);
	searchbox.addListener(this);

	addAndMakeVisible(searchButton);
	searchButton.addListener(this);

	/*addAndMakeVisible(deleteButton);
	deleteButton.addListener(this);*/

	formatManager.registerBasicFormats();

	loadLibrary();
	

}

MusicLibrary::~MusicLibrary()
{
	saveLibrary();
}

void MusicLibrary::paint (juce::Graphics& g)
{
	//header
	g.fillAll (getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background
	g.setColour(juce::Colours::black);
	g.drawRect(getLocalBounds(), 1);
	g.fillAll(juce::Colours::grey);
	g.setFont(28.0f);
	g.drawText("Music Library", getLocalBounds(),
		juce::Justification::top, true);

	//table
	g.setColour(juce::Colours::grey);
	g.drawRect(getLocalBounds(), 1);  
	g.setColour(juce::Colours::white);
	g.setFont(14.0f);
	  
	
	//searchbox
	searchbox.setFont(18.0f);
	searchbox.setTextToShowWhenEmpty(" Search", juce::Colours::grey);

	
}

void MusicLibrary::resized()
{
	TableList.setBounds(0, 28, getWidth(), getHeight());
	addButton.setBounds(getWidth()-100, 0, 100, 28);
	//deleteButton.setBounds(getWidth() - 150, 0, 50, 28);
	searchbox.setBounds(200, 0, 100, 28);
	searchButton.setBounds(300,0,50,28);
	searchButton.setBounds(300,0,50,28);
	
}

int MusicLibrary::getNumRows()
{
	return titles.size();
}

void MusicLibrary::paintRowBackground(juce::Graphics&g, 
									int rowNumber, 
									int width, 
									int height, 
									bool rowIsSelected)
{

	if (rowIsSelected)
	{
		g.fillAll(juce::Colours::orange);
		
	}
	else {
		g.fillAll(juce::Colours::darkgrey);
	}


}

void MusicLibrary::paintCell(juce::Graphics&g, 
							int rowNumber,
							int columnId,
							int width,
							int height,
							bool rowIsSelected)
{
	if (columnId==3)
	{
		g.drawText(titles[rowNumber],
			2, 0,
			width - 4, height,
			juce::Justification::centredLeft,
			true);
	}

	if (columnId ==4)
	{
		g.drawText(lengths[rowNumber],
			2, 0,
			width - 4, height,
			juce::Justification::centredLeft,
			true);
	}

}

juce::Component* MusicLibrary::refreshComponentForCell(int rowNumber,
														int columnId,
														bool isRowSelected,
														Component* existingComponentToUpdate)
{
	
	juce::TextButton* btn = dynamic_cast<juce::TextButton*>(existingComponentToUpdate);
	if (columnId == 1 || columnId == 2 || columnId ==5 && btn==nullptr)
	{
		if (columnId == 1) 
		{
			btn = new juce::TextButton("Deck 1");
		}
		if (columnId == 2)
		{
			btn = new juce::TextButton("Deck 2");
		}
		/*else if (columnId == 5)
		{
			btn = new juce::TextButton("Delete");
		}*/

		juce::String id{ std::to_string(rowNumber) };
		btn->setComponentID(id);
		btn->addListener(this);
		return btn;
	}
	else
	{
		return existingComponentToUpdate; 
	}

}

void MusicLibrary::buttonClicked(juce::Button* button)
{

	if (button == &addButton)
	{
		auto fileChooserFlags = juce::FileBrowserComponent::canSelectFiles;
		fChooser.launchAsync(fileChooserFlags, [this](const juce::FileChooser& chooser)
			{
				juce::File selectedFile = chooser.getResult();
		juce::URL audioURL = juce::URL{ selectedFile };
		loadURL(audioURL);
			});

	}

	/*if (button->getButtonText() == "Delete")
	{
		int row = std::stoi(button->getComponentID().toStdString());
		deleteFile(row);
	}*/
   
	if (button == &searchButton)
	{
		if (searchbox.isEmpty() != true)
		{
			std::string userInput = searchbox.getText().toStdString();
			searchLibrary(userInput);

		}

	}

	if (button->getButtonText() == "Deck 1")
	{
		int row = std::stoi(button->getComponentID().toStdString());
		Deck1(row);
	}

	if (button->getButtonText() == "Deck 2")
	{
		int row = std::stoi(button->getComponentID().toStdString());
		Deck2(row);
	}

}

void MusicLibrary::Deck1( int row)
{
	std::string title = titles[row];
	for (int i = 0; i < libraryFiles.size(); i++)
	{
		if (title == libraryFiles[i][0])
		{
			std::string filepath = libraryFiles[i][2];
			player1->loadURL(juce::URL{ juce::File{filepath} });
			deck1->loadWaveform(filepath);
			searchLibrary(libraryFiles[i][0]);
			
		}

	}
	
}

void MusicLibrary::Deck2( int row)
{
	std::string title = titles[row];
	for (int i = 0; i < libraryFiles.size(); i++)
	{
		if (title == libraryFiles[i][0])
		{
			std::string filepath = libraryFiles[i][2];
			player2->loadURL(juce::URL{ juce::File{filepath} });
			deck2->loadWaveform(filepath);
			searchLibrary(libraryFiles[i][0]);

		}

	}

}


void MusicLibrary::loadURL(juce::URL audioURL)
{
	auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
	if (reader != nullptr) // good file!
	{
		std::unique_ptr<juce::AudioFormatReaderSource> newSource
		(new juce::AudioFormatReaderSource(reader, true));
		transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);
		readerSource.reset(newSource.release());
		juce::File loadedFile = audioURL.getLocalFile();
		createLibraryFile(loadedFile);
		
	}
	else if(audioURL.isEmpty()!=true)
	{
		//closing browser or not choosing file doesn't trigger message
		juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
			"Error loading file",
			"The selected file could not be loaded. Only load audio files.",
			"OK");
	}
}

bool MusicLibrary::isInterestedInFileDrag(const juce::StringArray& files)
{
	return true;
}

void MusicLibrary::filesDropped(const juce::StringArray& files, int x, int y)
{
	if (files.size() == 1)
	{
		juce::URL audioURL = juce::URL{ juce::File{files[0]}};
		loadURL(audioURL);
	}
}

void MusicLibrary::createLibraryFile(const juce::File& file)
{
	auto reader = formatManager.createReaderFor(file);
	if (reader != nullptr)
	{
		std::string filename = file.getFileName().toStdString();
		const double lengthSeconds = reader->lengthInSamples /
			(double)reader->sampleRate;
		std::string length = std::to_string(lengthSeconds);
		std::string filepath = file.getFullPathName().toStdString();
		std::vector<std::string> newFile = { filename,length,filepath };
		
		//checks if file is already in library
		for (int i = 0; i < libraryFiles.size(); i++)
		{
			if (libraryFiles[i][0] == filename)
			{
				juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
					"File is already in your library.", "", "OK");
				searchLibrary(filename);
				return;
			}

		}
		libraryFiles.push_back(newFile);
		createList(libraryFiles.size(), filename, length);
		delete reader;
	}
	
}

void MusicLibrary::createList(int rowNumber, 
							std::string title, 
							std::string length)
{
	titles.push_back(title);
	lengths.push_back(length);
	refreshComponentForCell(rowNumber, 1, true, nullptr);
	refreshComponentForCell(rowNumber, 2, true, nullptr);
	TableList.updateContent();
	
}


void MusicLibrary::searchLibrary(std::string input)
{
	for (int i = 0; i < libraryFiles.size(); i++)
	{
		if (libraryFiles[i][0] == input)
		{
			titles.clear();
			lengths.clear();
			createList(1, libraryFiles[i][0], libraryFiles[i][1]);

			for (int j = 0; j < libraryFiles.size(); j++)
			{
				int rowNumber = j + 1;
				if (libraryFiles[j][0] != input)
				{
					createList(rowNumber, libraryFiles[j][0], libraryFiles[j][1]);
				}
				
			}
			break;
		}
		else if( libraryFiles.size()==i+1)
		{
			juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
				"File not found", "", "OK"); 
			return;
		}

	}
	
	TableList.updateContent();
}

void MusicLibrary::saveLibrary()
{
	//output text, for saving
	std::ofstream outFile("LibraryFiles.txt");
	if (outFile.is_open())
	{
		for (int i = 0; i < libraryFiles.size(); i++)
		{
			outFile << libraryFiles[i][0] 
				<< "," << libraryFiles[i][1] 
				<< "," << libraryFiles[i][2] << std::endl;
		}
		outFile.close();
	}
	else
	{
		DBG("SAVING FAILED");

	}

}

void MusicLibrary::loadLibrary()
{
	
	//input text, for reading
	std::ifstream loadFile("LibraryFiles.txt");
	if (loadFile.is_open())
	{
		std::string line;
		
		if (line != "")
		{
			while (std::getline(loadFile, line))
			{
				tokens = tokenize(line, ',');
				libraryFiles.push_back(tokens);
				titles.push_back(tokens[0]);
				lengths.push_back(tokens[1]);
			}
			loadFile.close();
			TableList.updateContent();

		}
		else { return; }
		
			
		
		
	}
	else
	{
		DBG("READING FAILED. ");
		return;
	}

}

//void MusicLibrary::deleteFile(int row)
//{
//
//	for (int i = 0; i < libraryFiles.size(); i++)
//	{
//		
//		if (titles[row] == libraryFiles[i][0])
//		{
//			titles.clear();
//			lengths.clear();
//			libraryFiles[i].clear();
//
//			int rowNumber;
//			for (int j = 0; j < libraryFiles.size(); j++)
//			{
//				rowNumber = j + 1;
//				createList(rowNumber, libraryFiles[i][0], libraryFiles[i][1]);
//			}
//			return;
//
//			/*for (int j = 0; j < libraryFiles.size(); j++)
//			{
//				if (libraryFiles[row][0] != libraryFiles[i][0])
//				{
//					createList(row, libraryFiles[i][0], libraryFiles[i][1]);
//
//				}
//				
//				
//			}
//
//			TableList.updateContent();
//			return;*/
//			
//		}
//	}
//
//}
	
std::vector<std::string> MusicLibrary::tokenize(std::string command, char separator)
{
	std::vector<std::string> tokens;
	signed int start, end;
	std::string token;
	start = command.find_first_not_of(separator, 0);
	do {
		end = command.find_first_of(separator, start);
		if (start == command.length() || start == end) break;
		if (end >= 0) token = command.substr(start, end - start);
		else token = command.substr(start, command.length() - start);
		tokens.push_back(token);
		start = end + 1;
	} while (end > 0);

	return tokens;

}



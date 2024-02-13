/*
  ==============================================================================

	PlaylistComponent.cpp
	Created: 24 Feb 2023 9:11:00pm

  ==============================================================================
*/

#include "PlaylistComponent.h"

//==============================================================================

//HW week 19
PlaylistComponent::PlaylistComponent()
{
	// In your constructor, you should add any child components, and
	// initialise any special settings that your component needs.
	addAndMakeVisible(tableComponent);
	tableComponent.getHeader().addColumn("", 1, 40);
	tableComponent.getHeader().addColumn("Title", 2, 400);
	tableComponent.getHeader().addColumn("Length", 3, 200);
	tableComponent.setModel(this);
	tableComponent.repaint();

	

}

PlaylistComponent::~PlaylistComponent()
{
}

void PlaylistComponent::paint (juce::Graphics& g)
{
	/* This demo code just fills the component's background and
	   draws some placeholder text to get you started.

	   You should replace everything in this method with your own
	   drawing code..
	*/

	DBG("paint IS CALLED");

	g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

	//Table List Heading
	g.setColour(juce::Colours::black);
	g.drawRect(getLocalBounds(), 1);
	g.fillAll(juce::Colours::grey);
	g.setFont(28.0f);
	g.drawText("Playlist", getLocalBounds(),
		juce::Justification::top, true);

	//table list
	g.setColour (juce::Colours::grey);
	g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
	g.setColour (juce::Colours::white);
	g.setFont (14.0f);
	g.drawText ("PlaylistComponent", getLocalBounds(),
				juce::Justification::centred, true);   // draw some placeholder text

	//juce::TableListBox table;
	//table.paint(g);
	//juce::Graphics g(juce::TableListBox);
	//juce:juce::TableListBox->paint(g);
}

void PlaylistComponent::resized()
{
	// This method is where you should set the bounds of any child
	// components that your component contains..
	tableComponent.setBounds(0, 28, getWidth(), getHeight());

}

int PlaylistComponent::getNumRows()
{
	return trackTitles.size();
}

void PlaylistComponent::paintRowBackground(juce::Graphics&g, 
										int rowNumber, 
										int width, 
										int height, 
										bool rowIsSelected)
{
	DBG("paintRowBackground in playlist IS CALLED");


	// just highlight selected rows
	if (rowIsSelected)
	{
		g.fillAll(juce::Colours::orange);
		
	}
	else {
		g.fillAll(juce::Colours::darkgrey);
	   
	}
}

void PlaylistComponent::paintCell(juce::Graphics&g, 
								int rowNumber, 
								int columnId, 
								int width, 
								int height, 
								bool rowIsSelected)
{
	DBG("paintCell in playlist IS CALLED");


	g.setColour(juce::Colours::black);
	g.setFont(14.0f);

	if (columnId == 2)
	{
		g.drawText(trackTitles[rowNumber], // the important bit
			2, 0,
			width - 4, height,
			juce::Justification::centredLeft,
			true);
	}
	
	if (columnId == 3)
	{
		g.drawText(trackLengths[rowNumber], // the important bit
			2, 0,
			width - 4, height,
			juce::Justification::centredLeft,
			true);
	}
   
}

//void PlaylistComponent::cellClicked(int rowNumber, int columnId, const juce::MouseEvent&)
//{
//    //std::cout << "Cell clicked - Row: " << rowNumber+1 << ", Column: " << columnId << std::endl;
//    DBG("CELL CLICKED!  column:"<<columnId<<"  row:"<<rowNumber+1);
//}

juce::Component* PlaylistComponent::refreshComponentForCell(
	int rowNumber,
	int columnId,
	bool isRowSelected,
	Component* existingComponentToUpdate)
{
	if (columnId == 1)
	{
		/*if (existingComponentToUpdate == nullptr)
		{
				juce::TextButton * btn = new juce::TextButton("play");
				juce::String id{ std::to_string(rowNumber) };
				btn->setComponentID(id);
				btn->addListener(this);
			existingComponentToUpdate = btn;

		}*/

		juce::TextButton* btn = dynamic_cast<juce::TextButton*>(existingComponentToUpdate);
		if (btn == nullptr)
		{
			btn = new juce::TextButton("play");
			juce::String id{ std::to_string(rowNumber) };
			btn->setComponentID(id);
			btn->addListener(this);
		}
		return btn;
	}
	return existingComponentToUpdate;
}

void PlaylistComponent::buttonClicked(juce::Button* button)
{
	//int id = std::stoi(button->getComponentID().toStdString());
	//DBG("PlaylistComponent::buttonClicked " << trackTitles[id]);

	if (button->getButtonText() == "+")
	{
		DBG("+ in Playlist was CLICKED");
		//turn button id string to integer
		
		
		for (int i = 0; i < trackTitles.size(); i++)
		{
			
				makeList(i, trackTitles[i], trackLengths[i]);


		}


	}

}

void PlaylistComponent::addFile(std::string filename, 
								std::string length, 
								std::string filepath)
{
	DBG("addFile CALLED ");
	DBG("FILENAME: "<< filename<<" Length: " << length <<" FILEPATH: " << filepath);
	
	std::vector<std::string> newFile = { filename,length,filepath };

	playlistFiles.push_back(newFile);

	makeList(playlistFiles.size(), filename, length);

}

void PlaylistComponent::makeList(int rowNumber,
								std::string title,
								std::string length)
{
	DBG("makeList IS CALLED");
	//if (rowNumber > 0)
	//{
	//	//trackTitles.push_back(playlistFiles[0][0]);
	//	//trackTitles.push_back(title);
	//	//trackLengths.push_back(playlistFiles[0][1]);
	//	//trackLengths.push_back(length);

	//	//tableComponent.updateContent();
	//	DBG("title is: "<< title);
	//	DBG("length is: "<< length);
	//	DBG("trackTitles is: "<< trackTitles[0]);
	//	DBG("trackLengths is: "<< trackLengths[0]);
	//	DBG("playlistfiles size is: "<< playlistFiles.size());
	//	DBG("playlistfiles 0 is: "<< playlistFiles[0][0]);
	//	DBG("playlistfiles 1 is: "<< playlistFiles[0][1]);
	//	DBG("numofRows is: "<< getNumRows());
	//}
	//else { DBG("playlist files size is 0 or negative"); }
	
	
		trackTitles.push_back(title);
		trackLengths.push_back(length);
		//paintCell(g,i, 2&3,getWidth(), getHeight(), true );
		
		DBG("numofRows is: " << getNumRows());
		//DBG("ColumnID is: " << getCellComponent(2,1));
	
		juce::TableListBox* updateContent();
	//tableComponent.updateContent();

	tableComponent.repaint();
	//tableComponent.resetContent();
	//refreshComponentForCell(rowNumber, 1, true, nullptr);
	//tableComponent.updateContent();
}

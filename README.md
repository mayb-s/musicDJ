R1.A 
The app can load files through the button “Add Music” in the Music Library or through drag and 
drop. It only takes certain formats for audio files, and when it can’t, it sends a message to the user about 
the file not being able to load. The function loadURL loads, then createLibraryFile reads, and pushes data 
into an array. The array is used to push data into the table with the function createList.  

R1.B 
It can play two tracks at the same time using the DJAudioPlayer from class. The audio loads and reads 
the files and uses juce::AudioTransportSource to make the audio play or stop. The Deck has a play or 
stop button and using the pointer “player” will call the functions in the audio player. In the main 
component there are two players, player 1 and player 2 and, deck 1 and deck 2. If I click play on deck 1, 
the pointer will play music in deck 1 and same with deck 2.  

R1.C 
The deck component DeckGUI has a slider for volume with a certain range. 
The deck uses the pointer “player” to set gain or get the value from setGain in 
DJAudioPlayer. The volume slider can vary volume for each deck when playing music.  

R1.D 
DeckGUI also has a rotary slider on both decks that slows down the track and speeds it up. The speed 
slider can be used to mix music with different tempos. It was declared in DeckGUI and used a pointer 
“player” to get the speed from DJAudioPlayer.  

R2.A and B 
I painted the DeckGUI according to my sketch. I decided to make different components, like the 
Turntable and Knob that I could then resize into DeckGUI. It fixed the distortions from stretching the 
page. The Turntable component has a spinning disk that the user can manipulate. To make this happen, I used the
pointer “player” and called Turntable in the DeckGUI callback function. It also 
starts and stops when the music stops.  

I changed the color scheme and put together the waveform with the position slider so the user can 
move the green spot in any part of the song. I did it with two sliders. One slider counts the seconds of 
the song and isn’t manipulated and the other slider is used the by user to change the part of the song.  

R3.A 
Reference R1A. I took out the original functions that loaded files directly onto the GUI and moved that 
functionality into the Music Library. The user clicks the load button and chooses from a browser or they 
can drag and drop. The file gets added but if they add a file that’s already in the Library, it will alert the 
user that it’s there and will show it on the top of the list.  

R3.B 
It doesn’t read from metadata because the audio files I used didn’t have or show any metadata like title 
or length. So instead, I read the filename and calculated the length in the function, createLibraryFile. The 
data is put into a vector and then that vector is put into the libraryFiles  array. Then, createList is called, 
which shows the data on the table.  

R3.C 
There is a search bar with a button that finds the song according to the name. It brings up the song to 
the top. It does this in the searchLibrary function which is also called createList. It reorganizes and redraws the 
list.  It is case-sensitive.  

R3.D 
Using pointers deck 1 and deck 2 in Music Library and using column IDs, I was able to click on deck 1 and 
deck 2 and load the file.

R3.E 
I made a text File called LibraryFiles.txt.  I created two functions, saveLibrary and loadLibrary. The "load" is 
called in the contructor and the "save" is called in the destructor. I also used a tokenizer as a 
function to read the file and print it out.  

R4A-C 
I changed the layout and color scheme and changed the functions and added more and took some out. I 
added two new components to the DeckGUI. The Music Library looks a little similar but I added a header 
and new buttons.  


// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #8: getSongPlayCount

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include "Listener.h"
#include "Song.h"

using namespace std;

/*
* This function accepts a string, delimiter character, array to store split strings and size of the array. It returns the number
* of strings the original string was split into.
* Parameters: string full, char delimit, string arr[], int size.
* Return: none
*/

void split (string full, char delimit, string arr[], int size)
{
    int s = full.length(); //length of string
    int check=0; //variable to keep track of the position of the strings being split
    int arrCheck=0; //variable to keep track of the array position
    int itemCounter=0; // variable to keep track of the number of split strings

    for(int i=0; i<s; i++) //going through the entire string
    {   
        int counter=0; //counter variable for split string's length
        if (full[i]==delimit) //this for loop runs to confirm the length of the split string after it encounters the delimiter character.
        {
            for (int j=check; j<i; j++) //loop to get the length of the split string
            {
                counter = counter+1;
            }

            arr[arrCheck] = full.substr(check,counter); //storing the split string using substr function
            arrCheck = arrCheck + 1;//increasing the number by 1 for array position
            check = i + 1;//position of the next string after the delimiter character's position
            itemCounter = itemCounter+1;//increasing string counter by 1
        }
    }
    //final split string
    int final = (s-check)+1; //starting position of final split string
    arr[arrCheck] = full.substr(check,final);//storing final split string
    itemCounter = itemCounter+1;//increasing string counter by 1 for 1 last time

    if(itemCounter>size) //condition for if the split strings are greater in number than the size of the array
    {
        itemCounter = -1;
    }
    
    else if(full == "") //conditon for case if user enters no value for string, then returning 0
    {
        itemCounter = 0;
    }
}

/*
* This function accepts a string for the name of the file, an array of Song class objects, int value of number of songs stored
* and a default array size of the Song class objects array as 50.
* Parameters: string fileName, Songs songs[], int numSongStored, int SongArrSize
* Return: updated value of numSongStored
*/

int readSongs(string fileName, Song songs[], int numSongStored, int songArrSize=50)
{
    songs[songArrSize];

    if (numSongStored == songArrSize) //case for when array is full 
    {
        return -2;
    }

    ifstream s1; //stream object

    s1.open(fileName); //opening file

    if (s1.fail()) //condition if entered file could not be opened
    {
        return -1;
    }

    char delimit = ','; //delimit character for split function

    int lineItems = 100; //arbitrary array size to store the split strings

    string storeLine; //string to store each line of the file

    string arr[lineItems]; //array store the split strings

    while(!s1.eof() && (numSongStored!=songArrSize)) //condition for while the file can be read and the songstored doesn't equal array size
    {
        getline(s1, storeLine); //storing file line in storeLine

        if(!isspace(storeLine[0]) && (storeLine.length() >1)) //condition for blank line 
        {
            split(storeLine, delimit, arr, lineItems); //calling the split function

            songs[numSongStored].setTitle(arr[0]); //using setTitle to store value from split string for objects at numSong
            songs[numSongStored].setArtist(arr[1]); //using setArtist to store value from split string for objects at numSong
            songs[numSongStored].setGenre(arr[2]); //using setGenre to store value from split string for objects at numSong

            numSongStored = numSongStored + 1; //increasing numSongStored if no blank line
        }
    }

    return numSongStored; //return numSongStored
}

/*
* This function accepts an array of Song objects and an int value of current songs stored. It then prints a list of the songs giving
* the song's title and artist
* Parameters: Song songs[], int numSongs
* Return: none
*/

void printAllSongs(Song songs[], int numSongs)
{
    if (numSongs <= 0) //case for when numSongs might not be greater than 0
    {
        cout << "No songs are stored" << endl;
    }
    else
    {   
        cout << "Here is a list of songs" << endl; //if there are stored songs then printing the list

        for(int i=0; i<numSongs; i++)
        {
            cout << songs[i].getTitle() << " is by " << songs[i].getArtist() << endl; //using getter functions
        }
    }
}

/*
* This function accepts a string for the name of the file, an array of Listener class objects, int value of number of listeners stored,
* the default size of the listener array size (100) and the maximum items in a line.
* Parameters: string fileName, Listener listeners[], int numListenersStored, int listenerArrSize = 100, int maxCol = 51
* Return: updated value of numListenersStored or specific integers for failure conditions
*/

int readListenerInfo (string filename, Listener listeners[], int numListenersStored, int listenerArrSize= 100, int maxCol= 51)
{   

    if (numListenersStored >= listenerArrSize)
    {
        return - 2;
    }

    ifstream l1;

    l1.open(filename);

    if (l1.fail())
    {
        return -1;
    }

    char delimit = ','; //delimit character for split function

    int lineItems = 100; //arbitrary array size to store the split strings

    string arr[lineItems];

    for (int i = 0; i<100; i++)
    {
        arr[i] = "0";
    }

    string storeLine;

    int blankCounter = 0;

    while(!l1.eof() && (numListenersStored!=listenerArrSize)) //condition for while the file can be read and the songstored doesn't equal array size
    {
        getline(l1, storeLine); //storing file line in storeLine

        if(!isspace(storeLine[0]) && (storeLine.length()>1)) //condition for blank line 
        {   

            blankCounter = blankCounter + 1;

            split(storeLine, delimit, arr, lineItems); //calling the split function

            listeners[numListenersStored].setListenerName(arr[0]); //using setTitle to store value from split string for objects at numSong

            for (int i = 0; i<maxCol; i++)
            {   
                string store = arr[i+1];
                int value = stoi(store);

                listeners[numListenersStored].setPlayCountAt(i, value);
            }
            numListenersStored = numListenersStored + 1; //increasing numSongStored if no blank line
        }
    }

    if (blankCounter == 0)
    {
        return 0;
    }
    return numListenersStored;
}

/*
* This function accepts a string for the name of listener, name of the song, an array of Listener class objects, an array of Song class objects,
* int value of listeners stored and an int value of songs stored. It returns the count of songs of the entered song for the required listener.
* Parameters: string listenerName, string songName, Listeners listeners[], Song songs[], int numListenersStored, int numSongsStored
* Return: int plays (count of songs)
*/


int getSongPlayCount( string listenerName, string songName, Listener listeners[], Song songs[], int numListenersStored, int numSongsStored)
{   
    int indexStore = -1;

    for (int i =0; i< numSongsStored; i++)
    {
        string charCheck = songs[i].getTitle();

        int stringCounter = 0;
        
        for (int j = 0; j < songName.length(); j++)
        {
            if (tolower(charCheck[j]) == tolower(songName[j]))
            {
                stringCounter = stringCounter + 1;
            }
        }

        if (stringCounter == songName.length())
        {
            indexStore = i; //index of song
        }
    }

    int listenersIndex = -1;

    for (int i = 0; i<numListenersStored; i++)
    {
        string listenerCheck = listeners[i].getListenerName();

        int listenerCounter = 0;

        for (int j = 0; j < listenerName.length(); j++)
        {
            if (tolower(listenerCheck[j]) == tolower(listenerName[j]))
            {
                listenerCounter = listenerCounter + 1;
            }
        }

        if (listenerCounter == listenerName.length())
        {
            listenersIndex = i;
        }
    }

    if ((listenersIndex!=-1) && (indexStore == -1))
    {
        return -1;
    }

    else if ((listenersIndex == -1) && (indexStore!= -1))
    {
        return -2;
    }
    else if ((listenersIndex == -1) && (indexStore == -1))
    {
        return -3;
    }
        int plays;

        plays = listeners[listenersIndex].getPlayCountAt(indexStore);

        return plays;
}

int main()
{
    Song songs[50];
    int numSongsStored = readSongs("songs2.txt", songs, 0, 50);
    cout << numSongsStored << endl;

    printAllSongs(songs, numSongsStored);

    int numListenersStored = 0;
    int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored =readListenerInfo("playlist1.txt", listener, numListenersStored, listenerArrSize, 50);

    cout << numListenersStored << endl;

    for (int i = 0; i<numListenersStored; i++)
    {
        cout << listener[i].getListenerName() << endl;

        for (int j=0; j<numSongsStored; j++)
        {
            cout << listener[i].getPlayCountAt(j) << endl;
        }
    }

    cout << getSongPlayCount("JOHN", "Goodbye Yellow BRICK Road", listener, songs, numListenersStored, numSongsStored) << endl;
}
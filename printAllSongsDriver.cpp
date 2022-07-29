// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #3: printAllSongs

#include <string>
#include <iostream>
#include "Song.h"

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

int main() //driver
{
    Song songs[10] = {};

    songs[0] = Song("The Long and Winding Road","The Beatles","Rock"); //parameterized constructor

    songs[1] = Song("Patches","Clarence Carter","Soul");

    songs[2] = Song(); //default constructor

    printAllSongs(songs, 3);

    songs[2].setArtist("Aretha Franklin"); //setter functions
    songs[2].setGenre("Soul");
    songs[2].setTitle("Angel");

    printAllSongs(songs, 3);

    Song songsTest[10]={};

    printAllSongs(songs,0);
}
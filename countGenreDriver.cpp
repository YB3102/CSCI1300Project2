// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #4: countGenre

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

/*
* This function accepts a string for the genre name, an array of songs objects and an int value for the number of songs stored.
* It then returns the value of the number of songs in the entered genre.
* Parameters: string genre, Song songs[], int numSongsStored
* Return: int counter (number of songs in the genre)
*/

int countGenre(string genre, Song songs[], int numSongsStored)
{
    int length = genre.length();

    int counter = 0;

    if (numSongsStored <= 0)
    {
        return 0; //returning 0 if songs are less or equal to 0
    }

    for (int i = 0; i<length; i++)
    {   
        char c = genre[i];

        if(i==0)
        {
            if (islower(c))
            {
                c = toupper(c);

                genre[i] = c;
            }
        }

        else if (genre[i-1] == ' ' && genre[i]!= 'a' && genre[i]!='A')
        {
            c = toupper(c);

            genre[i] = c;
        }

        else
        {
        if (isupper(c))
        {
            c = tolower(c);

            genre[i] = c;

        }
        }
    }

    for (int j=0; j<numSongsStored; j++) //loop to check if entered and required string are equal
    {
        string charCheck = songs[j].getGenre();

        int stringCounter = 0;

        for (int k=0; k<length; k++)
        {
            if(charCheck[k]== genre[k])
            {
                stringCounter = stringCounter + 1;
            }
        }

        if(stringCounter == length)
        {
            counter = counter + 1;
        }

    }

    return counter;
}
int main() //driver
{
    Song songs[10] = {};

    string genreRead = "Rock";

    songs[0] = Song("The Long and Winding Road","The Beatles","Rock"); //parameterized constructor

    songs[1] = Song("Patches","Clarence Carter","Soul");

    songs[2] = Song(); //default constructor

    cout << countGenre(genreRead, songs, 3) << endl;

    songs[2].setArtist("Aretha Franklin"); //setter functions
    songs[2].setGenre("Soul");
    songs[2].setTitle("Angel");

    cout << countGenre(genreRead, songs, 3) << endl;

    Song songsTest[10]={}; //empty array case

    cout << countGenre(genreRead, songsTest, 0) << endl;

}
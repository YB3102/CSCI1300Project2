// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #5: frequentGenreSongs

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
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

    int lineItems = 150; //arbitrary array size to store the split strings

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
        return 0;
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

    for (int j=0; j<numSongsStored; j++)
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

/*
* This function accepts an array of the song objects and an int value for the number of songs stored.
* It then returns the count of songs of the most frequent genre.
* Parameters: Song songs[], int numSongsStored
* Return: int maxOccur (the count of the songs of the most frequent genre)
*/

int frequentGenreSongs( Song songs[], int numSongsStored)
{   

    if(numSongsStored <= 0) //returning 0 if numSongStored are less than or equal to 0
    {
        return 0;
    }

    int maxOccur = 0;

    int tracker = 0;

    int countTracker = 0;

    string max;

    string genreTrack[numSongsStored];
    
    int countTrack[numSongsStored];

    for (int i =0; i<numSongsStored; i++)
    {
        countTrack[i] = 0;
    }

    for (int i=0; i<numSongsStored; i++)
    {
        for(int j = i+1; j<numSongsStored; j++)
        {
            if(songs[i].getGenre()==songs[j].getGenre())
            {
                break;
            }
        }
        genreTrack [countTracker] = songs[i].getGenre();  

        countTracker = countTracker + 1;
    }

    for (int i=0; i<countTracker; i++)
    {
        countTrack[i] = countGenre(genreTrack[i], songs, numSongsStored);
    }

    maxOccur = countTrack[0]; //initializing maxOccur as the first element of the countTrack array

    for (int i =0; i<countTracker; i++) //for loop to get the maxOccur
    {   

        if (countTrack[i] > maxOccur)
        {
            maxOccur = countTrack[i];

            tracker = i;
        }
    }

    max = genreTrack[tracker];

    return maxOccur; //returning maxOccur
}

int main()
{
    Song songs[10] = {};

    songs[0] = Song("The Long and Winding Road","The Beatles","Rock"); //parameterized constructor

    songs[1] = Song("Patches","Clarence Carter","Soul");

    songs[2] = Song(); //default constructor

    songs[2].setArtist("Aretha Franklin"); //setter functions
    songs[2].setGenre("Soul");
    songs[2].setTitle("Angel");

    int numSongsStored = 3;

    cout << frequentGenreSongs(songs, numSongsStored) << endl;
}

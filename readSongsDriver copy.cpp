// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Homework 7 - Problem #4: readSongs

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include "Song.h"

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
* Return: update value of numSongStored
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

    int lineItems = 5100; //arbitrary array size to store the split strings

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

int main()
{
 Song songs[10] = {};

 int storer = 0;

 int songsCurrent = 0;
 
 int arraySize = 0;

 string fileName;

 cout << "Enter filename: " << endl;

 getline(cin, fileName);

 cout << "Enter songs currently stored: " << endl;

 cin >> songsCurrent;

 cout << "Enter size of the array (less or equal to 50): " << endl;

 cin >> arraySize;

 int size=10;
 cout << readSongs(fileName,songs, songsCurrent, arraySize) << endl;

 storer =  readSongs(fileName,songs, songsCurrent, arraySize);

 if(storer>0) //printing the parameters using getter functions if value of stored songs is greater than 0
 {
 for(int i=0; i<storer; i++)
 {
     cout << songs[i].getGenre() << endl;

     cout << songs[i].getGenre().length() << endl;
 }
 }

}
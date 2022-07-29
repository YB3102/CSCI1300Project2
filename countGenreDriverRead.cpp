#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

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

void countGenre(string genre, Song songs[], int numSongsStored)
{
    int length = genre.length();

    int counter = 0;

    if (numSongsStored == 0)
    {
    }

    for (int i = 0; i<length; i++)
    {   
        char c = genre[i];

        if(i==0)
        {
            if (islower(c))
            {
                genre[i] = genre[i] -32;
            }
        }

        else if (genre[i-1] == ' ' && genre[i]!= 'a' && genre[i]!='A')
        {
            genre[i] = genre[i] - 32;
        }

        else if (i!=0)
        {
        if (isupper(c))
        {
            genre[i] = genre[i]+32;
        }
        }
    }

    for (int j=0; j<numSongsStored; j++)
    {   
        string check = songs[j].getGenre();

        cout << check << endl;

        cout << check.length() << endl;

        if (check == genre)
        {
            counter = counter + 1;
        }
    }

    cout << counter << endl;
}
int main() //driver
{
    Song songs[50] = {};

    int numSongsStored = 0;
    
    int songArrSize = 50;

    int i = readSongs("songs4.txt",songs,numSongsStored, songArrSize);

    countGenre("Pop", songs, i);
}
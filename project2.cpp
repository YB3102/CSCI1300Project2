// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #11: Put them together

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "Song.h"
#include "Listener.h"

using namespace std;

/*
* This function accepts a string, delimiter character, array to store split strings and size of the array. It returns the number
* of strings the original string was split into.
* Parameters: string full, char delimit, string arr[], int size.
* Return: int itemCounter (value of strings split into)
*/

int split (string full, char delimit, string arr[], int size)
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

    return itemCounter;
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
* This function accepts a string, delimiter character, array to store split strings and size of the array. It returns the number
* of strings the original string was split into.
* Parameters: string full, char delimit, string arr[], int size.
* Return: none
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

/*
* This function accepts a string for the name of listener, an array of Listener class objects, constant int value of number of songs,
* int value of listeners stored and the size of the listener object array. It then adds the listener and increases value of listeners by 1.
* Parameters: string listenerName, Listener listeners[], int const numSongs, int numListenersStored, int const listenerArrSize
* Return: updated value of numListenersStored or an integer value depending on error case.
*/


int addListener(string listenerName, Listener listeners[], int const numSongs, int numListenersStored, int const listenerArrSize = 100)
{   

    if (numListenersStored == listenerArrSize)
    {
        return -1;
    }

    else if(listenerName == "")
    {
        return -3;
    }

    int counter = 0;

    for (int i=0; i<numListenersStored; i++)
    {   
        string listenerCheck = listeners[i].getListenerName();

        for (int j = 0; j < listenerName.length(); j++)
        {   
            if (tolower(listenerName[j]) == tolower(listenerCheck[j]))
            {
                counter = counter + 1;
            }
        }

        if (counter == listenerName.length())
        {
            return -2;
        }
    }

    {
        listeners[numListenersStored].setListenerName(listenerName);

        for(int i=0; i< numSongs; i++)
        {
            listeners[numListenersStored].setPlayCountAt(i,0);
        }

        numListenersStored = numListenersStored + 1;
    }

    return numListenersStored;
}

/*
* This function accepts a string for the name of the file, an array of Listener class objects, int value of number of listeners stored,
* the default size of the listener array size (100) and the maximum items in a line.
* Parameters: string fileName, Listener listeners[], int numListenersStored, int listenerArrSize = 100, int maxCol = 51
* Return: updated value of numListenersStored or specific integers for failure conditions
*/

int readListenerInfo (string filename, Listener listeners[], int numListenersStored, int listenerArrSize= 100, int maxCol= 51)
{   

    ifstream l1;

    l1.open(filename);

     if (numListenersStored >= listenerArrSize)
    {
        return - 2;
    }

    else  if (l1.fail())
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

    int splitCounter = 0;

    while(!l1.eof() && (numListenersStored!=listenerArrSize)) //condition for while the file can be read and the songstored doesn't equal array size
    {
        getline(l1, storeLine); //storing file line in storeLine

        if(!isspace(storeLine[0]) && (storeLine.length()>1)) //condition for blank line 
        {   

            blankCounter = blankCounter + 1;

            splitCounter = split(storeLine, delimit, arr, lineItems); //calling the split function

            listeners[numListenersStored].setListenerName(arr[0]); //using setTitle to store value from split string for objects at numSong

            for (int i = 0; i<splitCounter-1; i++)
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

/*
* This function accepts a string for the name of listener, an array of Listener class objects, int value of listeners stored and int value of
* songs stored. It returns an int value depending on the cases and also prints the stats of the listener.
* Parameters: string listenerName, Listener listeners[], int numListenersStored, int numSongs
* Return: int values dependent on case.
*/

int getListenerStats(string listenerName, Listener listeners[], int numListenersStored, int numSongs)
{
    int counter = 0;

    int uniqueSum = 0;

    double uniqueAverage = 0;

    int listenerIndex = -1;

    for (int i = 0; i<numListenersStored; i++)
    {
        if (listenerName == listeners[i].getListenerName())
        {
            listenerIndex = i;
        }
    }

    if(listenerIndex == -1)
    {   
        cout << listenerName << " does not exist." << endl;
        return -3;
    }

    uniqueSum = listeners[listenerIndex].totalPlayCount();

    if(uniqueSum == 0)
    {   
        cout << listenerName << " has not listened to any songs." << endl;
        return 0;
    }

    counter = listeners[listenerIndex].getNumUniqueSongs();

    uniqueAverage = (double) uniqueSum/ (double) counter;

    cout << listeners[listenerIndex].getListenerName() << " listened to " << counter << " songs." << endl;

    cout << listeners[listenerIndex].getListenerName() << "'s average number of listens was "<< fixed << setprecision(2) << uniqueAverage << endl;

    return 1;  
}

int main()
{
    int choice = 0;
    int songNumber = 0;
    int listenerNumber = 0;
    Song songs[50];
    Listener listeners[100];
    
while (choice!=9)
{

    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read songs from file" << endl;
    cout << "2. Print all songs" << endl;
    cout << "3. Song-count by genre" << endl;
    cout << "4. Songs from most common genre" << endl;
    cout << "5. Add listener" << endl;
    cout << "6. Read listens from file" << endl;
    cout << "7. Get number of listens by a listener" << endl;
    cout << "8. Get listener statistics" << endl;
    cout << "9. Quit" << endl;

    cin >> choice;

    if (choice == 1)
    {   
        string fileName;
        int songPlaceHold;
        cout << "Enter a song file name: " << endl;

        cin.ignore();

        getline (cin, fileName);

        songPlaceHold = readSongs(fileName, songs, songNumber, 50);

        if(songPlaceHold == 50)
        {   
            songNumber = songPlaceHold;
            cout << "Total songs in the database: " << songNumber << endl;
            cout << "Database is full. Some songs may have not been added." << endl;
        }

        else if(songPlaceHold==-1)
        {
            cout << "No songs saved to the database." << endl;
        }
        else if(songPlaceHold==-2)
        {
            cout << "Database is already full. No songs were added." << endl;
            songNumber = 50;
        }
        else
        {
        songNumber = songPlaceHold;
        cout << "Total songs in the database: " << songNumber << endl;
        }

        choice = 0; //reset option
        
    }

    else if (choice == 2)
    {
        printAllSongs (songs, songNumber);

        choice = 0; //reset option
    }

    else if (choice == 3)
    {   
        string genreName; 
        int count;
        cout << "Genre:" << endl;

        cin.ignore();

        getline(cin, genreName);

        count = countGenre( genreName, songs, songNumber);

        cout << "Total " << genreName << " songs in the database: " << count << endl;

        choice = 0;
    }

    else if (choice == 4)
    {
        int count;

        count = frequentGenreSongs(songs, songNumber);

        cout << "Number of songs in most common Genre: " << count << endl;

        choice = 0;
    }

    else if (choice == 5)
    {   
        string listenerN;
        int listenerPlaceHold;
        cout << "Enter a listener name: " << endl;

        cin.ignore();

        getline(cin, listenerN);

        listenerPlaceHold = addListener(listenerN, listeners, songNumber, listenerNumber, 100);

        if(listenerPlaceHold == -1)
        {   
            cout << "Database is already full. Listener cannot be added." << endl;
        }

        else if(listenerPlaceHold == -2)
        {
           cout << "Listener already exists." << endl;
        }

        else if(listenerPlaceHold == -3)
        {
            cout << "The listenerName is empty." << endl;
        }
        else
        {
            listenerNumber = listenerPlaceHold;

            cout << "Welcome, " << listenerN << "!" << endl;
        }

        choice = 0;
    }

    else if (choice == 6)
    {
        string listenerFile;

        int listenerPlaceHolder;

        cout << "Enter the listener info file name: " << endl;

        cin.ignore();

        getline(cin, listenerFile);

        listenerPlaceHolder = readListenerInfo(listenerFile, listeners, listenerNumber, 100, 51);

        if (listenerPlaceHolder == -1)
        {
            cout << "Nothing saved to the database." << endl;
        }

        else if (listenerPlaceHolder == -2)
        {
            cout << "Database is already full. Nothing was added." << endl;
            listenerNumber = 100;

        }
        else if (listenerPlaceHolder == 100)
        {   
            listenerNumber = listenerPlaceHolder;

            cout << "Total listeners in the database: " << listenerNumber << endl;
            cout << "Database is full. Some listeners may have not been added." << endl;
        }
        else
        {
            listenerNumber = listenerPlaceHolder;

            cout << "Total listeners in the database: " << listenerNumber << endl;
        }

        choice = 0;
    }

    else if (choice == 7)
    {
        string listenerName;
        string songName;
        int listens;
        
        cout << "Enter a listener name: " << endl;

        cin.ignore();

        getline(cin, listenerName);

        cout << "Enter a song name: " << endl;

        getline(cin, songName);

        listens = getSongPlayCount(listenerName, songName, listeners, songs, listenerNumber, songNumber);

        if (listens == -1)
        {
            cout << songName << " does not exist." << endl;
        }

        else if (listens == -2)
        {
            cout << listenerName << " does not exist." << endl;
        }
        else if (listens == -3)
        {
            cout << listenerName << " and " << songName << " do not exist." << endl;
        } 
        else 
        {
            cout << listenerName << " has listened to " << songName << " " << listens << " times." << endl;
        }

        choice = 0;
    }

    else if (choice == 8)
    {   
        string listenerName;
        
        int stats;

        cout << "Enter a listener name:" << endl;

        cin.ignore();

        getline(cin, listenerName);

        stats = getListenerStats(listenerName, listeners, listenerNumber, songNumber);

        choice = 0;
    }

    else if (choice == 9)
    {
        cout << "Good bye!" << endl;
    }

    else 
    {
        cout << "Invalid input." << endl;

        choice = 0;
    }
}

}
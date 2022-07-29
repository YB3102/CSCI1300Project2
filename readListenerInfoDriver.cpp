// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #7: readListenerInfo

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
* Return: int itemCounter (number of strings the original string was split into)
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

    return itemCounter; //returning number of strings the original string was split into
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

    else if (l1.fail())
    {
        return -1;
    }

    char delimit = ','; //delimit character for split function

    int lineItems = 100; //arbitrary array size to store the split strings

    string arr[lineItems];

    for (int i = 0; i<100; i++)
    {
        arr[i] = "0"; //initializing every value as "0"
    }

    string storeLine; //string to store the extracted line from the file

    int blankCounter = 0; //counter to check if the file is empty

    int splitCounter = 0; //variable to store the value of the returned value of split function

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
                int value = stoi(store); //using stoi to store the values after getting listenerName

                listeners[numListenersStored].setPlayCountAt(i, value);
            }
            numListenersStored = numListenersStored + 1; //increasing numSongStored if no blank line
        }
    }

    if (blankCounter == 0) //returning 0 if file is empty
    {
        return 0;
    }
    return numListenersStored;
}

int main()
{
    int listenerArrSize = 2;
    Listener listeners[listenerArrSize];

    listeners[0].setListenerName("ritchie");
    listeners[0].setPlayCountAt(0,0);
    listeners[0].setPlayCountAt(1,1);
    listeners[0].setPlayCountAt(2,2);

    int numListenersStored = 1;

    numListenersStored = readListenerInfo("playlist1.txt", listeners, numListenersStored, listenerArrSize, 50);
}
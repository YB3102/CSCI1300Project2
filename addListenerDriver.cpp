// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #9: addListener

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include "Listener.h"

using namespace std;

/*
* This function accepts a string for the name of listener, an array of Listener class objects, constant int value of number of songs,
* int value of listeners stored and the size of the listener object array. It then adds the listener and increases value of listeners by 1.
* Parameters: string listenerName, Listener listeners[], int const numSongs, int numListenersStored, int const listenerArrSize
* Return: updated value of numListenersStored or an integer value depending on error case.
*/


int addListener(string listenerName, Listener listeners[], int const numSongs, int numListenersStored, int const listenerArrSize = 100)
{   
    int listenerLength = listenerName.length();

    if (numListenersStored == listenerArrSize)
    {
        return -1;
    }

    else if(listenerName=="")
    {
        return -3;
    }

    int counter = 0;

    for (int i=0; i<numListenersStored; i++)
    {   
        string listenerCheck = listeners[i].getListenerName();

        for (int j = 0; j < listenerLength; j++)
        {   
            if (tolower(listenerName[j]) == tolower(listenerCheck[j]))
            {
                counter = counter + 1;
            }
        }

        if (counter == listenerLength)
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

int main()
{
    Listener listeners[10];
    int listenersArrSize = 10;
    int numSongs = 5;

    listeners[0].setListenerName("Knuth");
    listeners[1].setListenerName("Richie");

    // Add play count for 5 songs
    for(int i=0; i<numSongs; i++) 
    {
    listeners[0].setPlayCountAt(i, i);
    listeners[1].setPlayCountAt(i, 5-i);
    }

    int numListenersStored = 2;

    int val = addListener("Ninja", listeners,numSongs, numListenersStored,listenersArrSize);

    cout<<"Total number of listeners in the array: "<< val<< endl;

    // Code to print the play counts
for(int i=0; i<val; i++)
 {
    cout<<listeners[i].getListenerName()<<" - ";
    for(int j=0; j<numSongs; j++) 
    {
    cout<<listeners[i].getPlayCountAt(j)<<",";
    }

    cout<<endl;
 }


}
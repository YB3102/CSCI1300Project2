// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #10: getListenerStats

#include <cctype>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "Listener.h"

using namespace std;

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

    cout << listeners[listenerIndex].getListenerName() << "'s average number of listens was " << fixed << setprecision(2) << uniqueAverage << endl;

    return 1;  
}

int main()
{
    //Creating 3 listeners
Listener listeners[3];
//Setting listenerName and num listens for Listener1
listeners[0].setListenerName("Listener1");
listeners[0].setPlayCountAt(0,1);
listeners[0].setPlayCountAt(1,4);
listeners[0].setPlayCountAt(2,2);
//Setting listenerName and num listens for Listener2
listeners[1].setListenerName("Listener2");
listeners[1].setPlayCountAt(0,0);
listeners[1].setPlayCountAt(1,5);
listeners[1].setPlayCountAt(2,3);
//Setting listenerName and num listens for Listener3
listeners[2].setListenerName("Listener3");
listeners[2].setPlayCountAt(0,0);
listeners[2].setPlayCountAt(1,0);
listeners[2].setPlayCountAt(2,0);

getListenerStats("Listener2", listeners, 3, 3);

getListenerStats("Listener3", listeners, 3, 3);

getListenerStats("Listener4", listeners, 3, 3);
}
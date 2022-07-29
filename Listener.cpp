// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #6: Listener Class Implementation

#include "Listener.h"      
#include <iostream>       
 
using namespace std;

Listener::Listener() //default constructor
{
    listenerName = "";

    for (int i = 0; i<size; i++)
    {
        playCount[i] = 0;
    }
}

Listener::Listener(string name, int count[], int arrSize) //parameterized constructor
{
    listenerName = name;

    if(arrSize>=size)
    {
        for(int i = 0; i<size; i++)
        {
            playCount[i] = count[i];
        }
    }

    else if(arrSize<size)
    {
        for(int i =0; i<arrSize; i++)
        {
            playCount[i] = count[i];
        }

        for (int j = arrSize; j<size; j++)
        {
            playCount[j] = 0;
        }
    }
}

//getters

string Listener :: getListenerName()
{
    return listenerName;
}

int Listener :: getPlayCountAt(int index)
{
    if (index >= size)
    {
        return -1;
    }

    else if (index < 0)
    {
        return -1;
    }

    else 
    {
        return playCount[index];
    }
}

int Listener :: getSize()
{
    return size;
}

//setters

void Listener :: setListenerName (string name)
{
    listenerName = name;
}

bool Listener :: setPlayCountAt(int index, int value)
{
    if( (index<size && index >= 0) && (value>0) )
    {
        playCount[index] = value;

        return true;
    }

    else
    {
        return false;
    }
}

//function to get the total play count of the user

int Listener :: totalPlayCount()
{
    int sum = 0;
    
    for (int i = 0; i<size; i++)
    {
        sum = sum + playCount[i];
    }

    return sum;
}

//function to get the unique songs listened by listener

int Listener :: getNumUniqueSongs()
{
    int counter = 0;

    for (int i = 0; i<size; i++)
    {
        if (playCount[i] >= 1)
        {
            counter = counter + 1;
        }
    }

    return counter;
}
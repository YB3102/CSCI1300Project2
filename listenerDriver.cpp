// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #6: Listener Class driver program

#include "Listener.h"      
#include <iostream>    

using namespace std;

int main()
{
    Listener ob1 = Listener(); //default constructor

    cout << "Name: " << ob1.getListenerName() << endl;
    cout << "PlayCountAt: "<< endl;
    for (int i=0 ; i<ob1.getSize(); i++)
    {
        cout << ob1.getPlayCountAt(i) << endl;
    }
    cout << "Size: " << ob1.getSize() << endl;

    string name = "Jack";
    ob1.setListenerName(name); //setter for name
    cout << "Name: " << ob1.getListenerName() << endl;

    int count[] = {7,2,0,5,3,2,0,6,7,9,6,9,6,6,1,1,6,9,4,1,8,7,1,1,7,7,9,9,1,1,9,0,1,6,0,2,5,8,8,8,3,2,8,4,5,5,0,2,9,0};

    for ( int i=0; i<ob1.getSize(); i++)
    {
        bool countSet = ob1.setPlayCountAt (i, count[i]);
    }

    for ( int i=0; i<ob1.getSize(); i++)
    {
        cout << ob1.getPlayCountAt(i) << endl;
    }

    string obj2Name = "Lewis";

    int arrSize = 50;

    int countobj2[] = {6,5,3,2,0,6,9,9,6,0,0,5,0,1,1,0,4,9,0,2,5,6,8,2,9,7,0,3,6,8,7,3,1,1,9,8,9,7,9,3,0,3,9,2,4,8,8,4,0,2};

    Listener ob2 = Listener (obj2Name, countobj2, arrSize); //parameterized constructor call

    cout << "Name: " << ob2.getListenerName() << endl;

    for ( int i=0; i<ob2.getSize(); i++)
    {
        cout << ob2.getPlayCountAt(i) << endl;
    }

}
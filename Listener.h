// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #6: Listener Class

#include <string>
using namespace std;

class Listener
{

    public:

    Listener(); //default constructor

    Listener(string name, int count[], int arrSize); //parameterized constructor

    string getListenerName(); //getters
    int getPlayCountAt(int index);
    int getSize();

    void setListenerName(string name); //setters
    bool setPlayCountAt(int index, int value);

    int totalPlayCount();

    int getNumUniqueSongs();

    private: //private data variables

    string listenerName;

    int static const size = 50;

    int playCount[size];

};
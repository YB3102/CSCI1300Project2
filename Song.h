// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #1: Song Class
#include <string>
using namespace std;

class Song
{
    public:

    Song(); //default constructor

    Song(string titleSong, string artistName, string genreName); //parameterized constructor

    string getTitle(); //getters
    string getArtist();
    string getGenre();

    void setTitle(string titleSong); //setters
    void setArtist(string artistName);
    void setGenre(string genreName);

    private : 

    string title; //private data variables

    string artist;

    string genre;
    
};
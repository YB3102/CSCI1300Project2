// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #1: Song Class Implementation

#include "Song.h"      
#include <iostream>       
 
using namespace std;

Song::Song() //default constructor
{   
    title="";
    artist="";
    genre="";
}

Song::Song(string titleSong, string artistName, string genreName) //parameterized constructor
{
    title = titleSong;
    artist = artistName;
    genre = genreName;
}

//getters

string Song::getTitle()
{
    return title;
}

string Song::getArtist()
{
    return artist;
}

string Song::getGenre()
{
    return genre;
}

//setters

void Song::setTitle(string titleSong)
{
    title = titleSong;
}

void Song::setArtist(string artistName)
{
    artist = artistName;
}

void Song::setGenre(string genreName)
{
    genre = genreName;
}
// CSCI 1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Project 2 - Problem #1: Song Class driver program

#include "Song.h"      
#include <iostream>       

int main()
{
    Song ob1 = Song(); //default constructor

    cout << "Title: " << ob1.getTitle() << endl;
    cout << "Artist: " << ob1.getArtist() << endl;
    cout << "Genre: " << ob1.getGenre() << endl;

    string title = "Love Me Do";
    ob1.setTitle(title); //setter for title
    cout << "Title: " << ob1.getTitle() << endl;

    string artist = "The Beatles";
    ob1.setArtist(artist); //setter for artist
    cout << "Artist: " << ob1.getArtist() << endl;

    string genre = "Rock";
    ob1.setGenre(genre); //setter for genre
    cout << "Genre: " << ob1.getGenre() << endl;

    Song ob2 = Song(title, artist, genre); //parameterized constructor
    cout << "Title: " << ob2.getTitle() << endl;
    cout << "Artist: " << ob2.getArtist() << endl;
    cout << "Genre: " << ob2.getGenre() << endl;

}
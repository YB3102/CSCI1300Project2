# CSCI 1300 - Project 2

---

Project 2 - README <br>
CSCI 1300 Fall 21 <br>
Project Name - Song Library <br>

Authors: Yatharth Brahmbhatt (me)

This project helped me learn applications of objects and classes. This project is about a song library which records listeners and songs into the library. The program reads and writes info on songs and listeners in the library. There are class specific functions for both listeners and songs. <br>
The main program is contained in the project2.cpp file. The functions for this file were tested separately in driver cpp files which are named the same as their functions. There are also driver functions to test the class functions of the Song and Listener classes. <br>
Finally, the main program has a text-based menu through which the user can manipulate the library record for the songs and listeners. They can have the program read listener and song info from text files. They can count songs from a particular song, they can display the stats of a listener, the most frequently listened genre, etc. <br>

There are also various txt files provided to test reading song info, and listener info. Some of these text files also test for edge cases. <br>

The files and code have been compiled using the following command in wsl terminal: <br>
g++ -std=c++17 CSCI1300Project2/Song.cpp CSCI1300Project2/Listener.cpp CSCI1300Project2/project2.cpp
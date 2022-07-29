// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA Meenakshi Sistla
// Homework 5 : Problem #5 : Question 5 : split a string
#include <iostream>
#include <string>
using namespace std;

/*
* This function accepts a string, delimiter character, array to store split strings and size of the array. It returns the number
* of strings the original string was split into.
* Parameters: string full, char delimit, string arr[], int size.
* Return: integer value of number of strings the original string was split into.
*/

int split (string full, char delimit, string arr[], int size)
{
    int s = full.length(); //length of string
    int check=0; //variable to keep track of the position of the strings being split
    int arrCheck=0;//variable to keep track of the array position
    int itemCounter=0;// variable to keep track of the number of split strings

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
    return itemCounter; //returning item counter for split string number
    
}

int main()
{
    string enter;
    char j;
    int arrsize;
    int arrnumber;
    string jinput;

    cout << "enter string" << endl;
    getline(cin,enter);

    cout << "enter delimiter char" << endl;

    getline(cin,jinput);
    j = jinput[0];

    cout << "size" << endl;

    cin >> arrsize;

    string Array[arrsize];

    arrnumber = split(enter, j, Array, arrsize);

    cout << "The number of split string are: " << arrnumber << endl;

    return 0;

}
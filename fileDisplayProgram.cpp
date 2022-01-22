/*
   Author: Steven Bertolucci
   Class: CSIS 297
   Description: Assignment #4
 
 
   main.cpp
   File Display Program

   Created by Steven Bertolucci on 3/7/14.
   Copyright (c) 2014 Steven Bertolucci. All rights reserved.
*/

#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

int main()
{
    int output = 0;
    string fileName, input;
    fstream dataFile;
    
    // Ask user for file name
    cout << "Enter a file name: ";
    getline(cin, fileName);
    
    dataFile.open(fileName, ios::in | ios::out);
    
    // If file exists, display the lines
    if (dataFile)
    {
        getline(dataFile, input);
        
        while (dataFile.eof())
        {
            getline(dataFile, input);
            cout << input << endl;
            output++;
            if (output == 24)
            {
                cout << "Hit enter to see more lines. ";
                cin.get();
                output = 0;
            }
        }
        //close the file
        dataFile.close();
    }
    
    // If it does not exist, display an error message
    else
    {
        cout << "ERROR: Can't open the file.\n";
    }
    
    //Show the user that it's done
    cout << "File converson done.\n";
   
    return 0;
}


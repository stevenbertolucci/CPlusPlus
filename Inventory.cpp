/*
    Author: Steven Bertolucci
    Assignment: Project
 
    Description: This is a C++ test driver for any small, local business who wishes to
    start a business and needs a simple, small, and readable software to maintain
    their inventory/database.
 
    main.cpp
    Inventory
 
    Created by Steven Bertolucci on 3/25/14.
    Copyright (c) 2014 Steven Bertolucci. All rights reserved.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "Employee.h"
using namespace std;

// Prefix operator++
Inventory Inventory::operator++()
{
    ++amount;
    return *this;
}

// Prefix operator--
Inventory Inventory::operator--()
{
    --amount;
    return *this;
}

// Postfix operator++
Inventory Inventory::operator++(int)
{
    amount++;
    return *this;
}

// Postfix operator--
Inventory Inventory::operator--(int)
{
    amount--;
    return *this;
}

// Bool relational operator
bool Inventory::operator > (int &amount)
{
    bool status;
    
    if (amount > 0)
        status = true;
    else
        status = false;

    return status;
}

// Bool relational operator
bool Inventory::operator < (int &amount)
{
    bool status;
    
    if (amount < 0)
        status = true;
    else
        status = false;
    
    return status;
}

ostream &operator << (ostream &strm, const Inventory &obj)
{
    strm << "Hello";
    strm << obj.description << " , " << obj.amount << " , " << obj.price << " ";
    return strm;
}

istream &operator >> (istream &strm, Inventory &obj)
{
    // Prompt the user for Description
    cout << "Description: ";
    strm >> obj.description;
    
    // Prompt the user for amount
    cout << "Amount: ";
    strm >> obj.amount;
    
    // Prompt user for Price
    cout << "Price: ";
    strm >> obj.price;
    
    return strm;
}

int Employee::getRemainingWorkYears() const
{
    int reqYears = 100, remainingYears;
    
    // Calculate the remaining hours
    remainingYears = reqYears - (age);
    
    return remainingYears;
}

//Function Prototype
void displayMenu();
bool checkPassword(string);
void checkInventory(char);
void addInventory();
void subtractInventory();






int main()
{
    // Local Variable
    int a, age;
    char userChoice, userInput;
    string thePassword, userName; // to hold password, userInfo
    // Create the Employee Object
    Employee userInfo;
    const int NUM_ITEMS = 30;
    Inventory inventory[NUM_ITEMS] = {
        Inventory(5, 8.0, 40.0, "Hammer"),
        Inventory(3, 20.0, 60.0, "Chainsaw"),
        Inventory(14, 7.0, 98.0, "Pliers"),
        Inventory(20, 13.0, 260.0, "Ratchet"),
        Inventory(182, 1.0, 182.0, "Screws"),
        Inventory(50, 15.0, 750.0, "ScrewDriver"),
        Inventory(400, 60, 24000.0, "Wood"),
        Inventory(34, 3.0, 102.0, "Scissors"),
        Inventory(13, 33.5, 175.5, "Drill"),
        Inventory(55, 12.0, 660.0, "Hose"),
        Inventory(245, 23.45, 5745.25, "Cement"),
        Inventory(7, 120.0, 840.0, "Wheelbarro"),
        Inventory(68, 12.0, 816.0, "Axe"),
        Inventory(15, 34.95, 524.25, "Snake"),
        Inventory(88, 9.55, 840.4, "Sprinklers"),
        Inventory(235, 22.99, 5402.65, "Fertilizer"),
        Inventory(15, 750.0, 11250.0, "BBQ"),
        Inventory(20, 1549.99, 30999.8, "Lawn Mower"),
        Inventory(2000, 1.25, 2500.0, "Nails"),
        Inventory(900, 14.99, 13491.0, "Paint"),
        Inventory(500, 34.99, 17495.0, "Tiles"),
        Inventory(90, 9.0, 810.0, "Light Bulbs"),
        Inventory(30, 7.0, 210.0, "Plunger"),
        Inventory(66, 6.10, 402.6, "Pipes"),
        Inventory(125, 15.0, 1875.0, "Grass"),
        Inventory(12, 20.0, 240.0, "Weed Wacker"),
        Inventory(45, 18.0, 810.0, "Fans"),
        Inventory(70, 24.99, 1749.3, "Sledgehammer"),
        Inventory(17, 15.99, 271.83, "Goggles"),
        Inventory(2, 1539.99, 3079.98, "ForkLift")
    };
    
    // Request Info from the Employee
    cout << "Enter your Username: ";
    getline(cin, userName);
    
    userInfo.setEmployeeName(userName);
    
    // Authorize the user first...
    cout << "Enter the password: ";
    cin >> thePassword;
    
    // Check the password
    a = checkPassword(thePassword);
    
    // If password is incorrect, stop the program
    if (a == false)
        exit(EXIT_FAILURE);
    
    // If the passwrod is correct, continue the program and display menu
    do {

        displayMenu();
        cin >> userChoice;
        cout << endl;
    
        // Input Validation
        while (toupper(userChoice) < 'A' || toupper(userChoice) > 'G')
        {
            cout <<  "Invalid Choice. Choose again: ";
            cin >> userChoice;
        }
        
        switch (toupper(userChoice)) {
            case 'A':
                cout << "What would you like to look up? ";
                cin >> userInput;
                checkInventory(userInput);
                break;
            
            case 'B':
                addInventory();
                break;
        
            case 'C':
                subtractInventory();
                break;
        
            case 'D':
            {
                
            cout << setw(1) << "Amount" << setw(12) << "Price" << setw(14) << "Total" << setw(20) << "Inventory\n";
            cout << "----------------------------------------------------------\n";
            
                for (int i = 0; i < NUM_ITEMS; i++)
                {
                    cout << setprecision(2) << fixed;
                    cout << setw(14) << left << inventory[i].getAmount();
                    cout << setw(14) << inventory[i].getPrice();
                    cout << setw(14) << inventory[i].getTotalAmount();
                    cout << setw(14) << inventory[i].getDescription() << endl;
                }

            }
            break;
                
            case 'E':
                cout << "What is your age? ";
                cin >> age;
                userInfo.setAge(age);
                cout << userInfo.getEmployeeName() << ", you have " << userInfo.getRemainingWorkYears() << " years of work left.\n";
                break;
                
        
            case 'F':
                system(EXIT_SUCCESS);
                break;
        }
    } while (toupper(userChoice) != 'F');
    
    
    return 0;
}







// Functions
void displayMenu() {
    
    cout << "\n\t\t\t\tWelcome!\n\n\t\tWhat would you like to do?\n\n";
    cout << "\tA. Check Inventory.\n\tB. Add Inventory.\n\tC. Subtract Inventory."
    << "\n\tD. Show All Inventory.\n\tE. Check Remaining Work Years.\n\tF. Log Out\n\n";
}

/*void getPassword() {
    START:
        system("cls");
        cout << "\nEnter password: ";
        char pass[32];
        int i = 0;
        char a;
        for (i = 0;;)
        {
            a = getchar();
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >='0' && a <= '9'))
            {
                pass[i] = a;
                ++i;
                cout << "*";
            }
            
            if (a == '\b' && i>=1)
            {
                cout << "\b \b";
                --i;
            }
            
            if (a=='\r')
            {
                pass[i] = '\0';
                break;
            }
        }
    
        cout << "\nYou entered: " << pass;
        if (i <= 5)
        {
            cout << "\nMinimum 6 digits needed. enter again";
            getchar(); // it was not pausing
            goto START;
        }
}*/

bool checkPassword(string password) {
    
    if (password != "alias")
    {
        cout << "Access Denied!\n";
        return false;
    }
    else
    {
        cout << "Access Granted!\n";
        return true;
    }
    
}

void checkInventory(char userInput) {
    const int NUM_PRODS = 30;
    const int LENGTH = 40;
    char products[NUM_PRODS][LENGTH] = {
                "5, 8.0, 40.0, Hammer",
                "3, 20.0, 60.0, Chainsaw",
                "14, 7.0, 98.0, Pliers",
                "20, 13.0, 260.0, Ratchet",
                "182, 1.0, 182.0, Screws",
                "50, 15.0, 750.0, ScrewDriver",
                "400, 60, 24000.0, Wood",
                "34, 3.0, 102.0, Scissors",
                "13, 33.5, 175.5, Drill",
                "55, 12.0, 660.0, Hose",
                "245, 23.45, 5745.25, Cement",
                "7, 120.0, 840.0, Wheelbarro",
                "68, 12.0, 816.0, Axe",
                "15, 34.95, 524.25, Snake",
                "88, 9.55, 840.4, Sprinklers",
                "235, 22.99, 5402.65, Fertilizer",
                "15, 750.0, 11250.0, BBQ",
                "20, 1549.99, 30999.8, Lawn Mower",
                "2000, 1.25, 2500.0, Nails",
                "900, 14.99, 13491.0, Paint",
                "500, 34.99, 17495.0, Tiles",
                "90, 9.0, 810.0, Light Bulbs",
                "30, 7.0, 210.0, Plunger",
                "66, 6.10, 402.6, Pipes",
                "125, 15.0, 1875.0, Grass",
                "12, 20.0, 240.0, Weed Wacker",
                "45, 18.0, 810.0, Fans",
                "70, 24.99, 1749.3, Sledgehammer",
                "17, 15.99, 271.83, Goggles",
                "2, 1539.99, 3079.98, ForkLift"
    };

    char lookUp[LENGTH]; // to hold user input
    char *strPtr = NULL; // to point to the found product
    int index;
   
    cin.getline(lookUp, LENGTH);
    
    // search array
    for (index = 0; index < NUM_PRODS; index++)
    {
        strPtr = strstr(products[index], lookUp);
        if (strPtr != NULL)
            break;
    }
    
    // Display the product info
    if (strPtr != NULL)
    {
        cout << setw(1) << "\nAmount" << setw(12) << "Price" << setw(14) << "Total" << setw(20) << "Inventory\n";
        cout << "----------------------------------------------------------\n";
        cout << products[index] << endl;
    }
    else
        cout << "No matching product was found.\n";
    
}

void addInventory() {
    // Create the objects
    Inventory add;
    Inventory inventory;
    
    string userInput;
    int userInput2;
    double userInput3;
    
    cout << "What inventory would you like to add? ";
    cin >> userInput;
    add.setDescription(userInput);
    
    cout << "How much do you you have in hand? ";
    cin >> userInput2;
    add.setAmount(userInput2);
    
    cout << "How much does it cost per item? ";
    cin >> userInput3;
    add.setPrice(userInput3);
    
    Inventory(userInput2, userInput3, userInput);
    
    cout << "\nSucessfully added to inventory!\n\n";
    cout << setw(1) << "Amount" << setw(12) << "Price" << setw(18) << "Inventory" << endl;
    cout << "----------------------------------------------\n";
    cout << setprecision(2) << fixed;
    cout << setw(14) << left << add.getAmount();
    cout << setw(14) << add.getPrice();
    cout << setw(14) << add.getDescription() << endl;
}

void subtractInventory() {
    // Create another object
    Inventory subtract;
    string userInput;
    int userInput2, userInput3;
    
    cout << "What inventory do you wish to subtract? ";
    cin >> userInput;
    
    cout << "How many are in stock? ";
    cin >> userInput2;
    
    cout << "How many do you wish to remove? ";
    cin >> userInput3;
    
    subtract.setDescription(userInput);
    subtract.setAmount(userInput2);
    subtract.subtractAmount(userInput2, userInput3);
    
    cout << "\nSucessfully subtracted item from inventory!\n\n";
    cout << setw(1) << "Amount" << setw(18) << "Inventory" << endl;
    cout << "----------------------------------------------\n";
    cout << setprecision(2) << fixed;
    cout << setw(14) << left << subtract.getAmount();
    cout << setw(14) << subtract.getDescription() << endl;
    
}


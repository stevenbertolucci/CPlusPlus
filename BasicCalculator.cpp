//
//  main.cpp
//  Calculation Program
//
//  Created by Steven Bertolucci on 1/7/14.
//  Copyright (c) 2014 Steven Bertolucci. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function Prototype
int getMultiplication(), getAddition(), getSubtraction(),
getSquare();
double getDivision(), getSquareRoot(), getQuadratic();

int main()
{
    int userInput;
    
    cout << "Hello, Welcome to Calculation World!\n\nWhat would you like to do?\n"
        << "1. Multiply\n2. Divide\n3. Add\n4. Subtract\n5. Square the number\n"
        << "6. Find the square root\n7. Solving quadratic equation.\n\n"
        << "Please enter your choice: ";
    cin >> userInput;
    
    while (userInput < 1 || userInput > 7)
    {
        cout << "Invalid number. Please try again: \n";
        cin >> userInput;
    }
    
    switch (userInput)
        {
            case 1:
                getMultiplication();
                break;
            
            case 2:
                getDivision();
                break;

            case 3:
                getAddition();
                break;
            
            case 4:
                getSubtraction();
                break;
            
            case 5:
                getSquare();
                break;
            
            case 6:
                getSquareRoot();
                break;
    
            // This function does not work. Need fixing!
            case 7:
                getQuadratic();
                break;
        }

    
    return 0;
}

int getMultiplication()
{
    int number1, number2, answer;
    
    cout << "Please enter first number: \n";
    cin >> number1;
    cout << "Now the second number: \n";
    cin >> number2;
    
    answer = number1 * number2;
    
    cout << "The product of those two numbers are " << answer << ".\n";
    
    return answer;
}

double getDivision()
{
    int number1, number2;
    double answer;
    
    cout << "Please enter first number: \n";
    cin >> number1;
    cout << "Now the second number: \n";
    cin >> number2;
    
    answer = (double)number1 / number2;
    
    setprecision(2);
    cout << "The division of those two numbers are " << answer << ".\n";
    
    return answer;
}

int getAddition()
{
    int number1, number2, answer;
    
    cout << "Please enter first number: \n";
    cin >> number1;
    cout << "Now the second number: \n";
    cin >> number2;
    
    answer = number1 + number2;
    
    cout << "The addition of those two numbers are " << answer << ".\n";
    
    return answer;
}

int getSubtraction()
{
    int number1, number2, answer;
    
    cout << "Please enter first number: \n";
    cin >> number1;
    cout << "Now the second number: \n";
    cin >> number2;
    
    answer = number1 - number2;
    
    cout << "The subtraction of those two numbers are " << answer << ".\n";
    
    return answer;
}

int getSquare()
{
    int number1, answer;
    
    cout << "Please enter first number: \n";
    cin >> number1;
    
    answer = number1 * number1;
    
    cout << "The square of " << number1 << " is " << answer << ".\n";
    
    return answer;
}

double getSquareRoot()
{
    int number1;
    double answer;
    cout << "Please enter first number: \n";
    cin >> number1;
    
    answer = sqrt(number1);
    
    setprecision(2);
    cout << "The square root of " << number1 << " is " << answer << ".\n";
    
    return answer;
}

double getQuadratic()
{
    int a, b, c;
    double answer;
    cout << "What is the value of a?\n";
    cin >> a;
    cout << "What is the value of b?\n";
    cin >> b;
    cout << "What is the value of c?\n";
    cin >> c;
    
    answer = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    cout << "One of the answer is " << answer << ".\n";
    
    answer = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    cout << "The other is " << answer << ".\n";
    
    
    return answer;
}


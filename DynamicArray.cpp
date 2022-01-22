/*
    Name: Steven Bertolucci
    Description: Assignment #1
 
    Test Scores #1: Write a program that dynamically allocates an array 
    large enough to hold a user-defined number of test scores. Once all 
    the scores are entered, the array should be passed to a function that 
    sorts them in ascending order. Another function should be called that 
    calculates the average score. The program should display the sorted
    list of scores and averages with appropriate headings.
    Use pointer notation rather than array notation whenever possible.


    Created by Steven Bertolucci on 1/28/14.
    Copyright (c) 2014 Steven Bertolucci. All rights reserved.

*/

#include <iostream>
#include <string>
using namespace std;

int getTestScores(int *, int);
void getStudentFullNames(int *, int);
double getAverage(int *, int);
void SortArray(int *, int);
void ShowArray(const int *, int);

int main()
{
    int tests = 0, numbers[tests];
    string studentNames;
    // int studentNames = 0, studentFullNames[studentNames];
    
    // Ask User for number of tests
    cout << "How many tests do you have? \n";
    cin >> tests;
    
    // Get test scores
    numbers[tests] = getTestScores(numbers, tests);
    
    // getStudentFullNames(studentFullNames, tests);
    
    
    // Assign student names to test scores
    cout << "\nEnter the names of the students in order of tests you submitted:\n";
    for (int i = 0; i < tests; i++)
    {
        cin >> studentNames;
        cout << "" << studentNames << " scored " << *(numbers + i) << endl;
    }

    // Pass the array to Sort Function
    SortArray(numbers, tests);
    
    //Display the Sorted Array
    ShowArray(numbers, tests);
    
    // Get Average
    getAverage(numbers, tests);
    
    return 0;
}


// get test scores from user
int getTestScores(int *arr, int size)
{
    int *test;
    
    // dynamically allocate array for test scores
    test = new int[size];
    
    // Get test scores from User
    cout << "Please enter the test scores or -1 to quit:\n";
    for (int count = 0; count < size; count++)
    {
        cout << "Test " << (count + 1) << ": ";
        cin >> *(arr + count);
    }
    
    // Free dynamically allocated memory
    delete [] test;
    
    return *arr;
}

/* I can't make this function work.
void getStudentFullNames(int *names, int size)
{
    const int SIZE = 50;
    char fullName[SIZE];
    
    // Get Names from User
    cout << "Please enter the names of the students that"
    << " took the tests:\n";
    for (int count = 0; count < size; count++)
    {
       
        cout << "Student " << (count + 1) << ": ";
        cin.ignore();
        cin.getline(fullName, SIZE) >> *(names + count);
    }
    
}
*/

// sort array using Selection Sort
void SortArray(int *arr, int size)
{
    int scan, minIndex, minValue;
    
    for (scan = 0; scan < (size - 1); scan++)
    {
        minIndex = scan;
        minValue = *(arr + scan);
        for (int index = scan + 1; index < size; index++)
        {
            if ( *(arr + index) < minValue)
            {
                minValue = *(arr + index);
                minIndex = index;
            }
        }
        *(arr + minIndex) = *(arr + scan);
        *(arr + scan) = minValue;
    }
}

// Get Average
double getAverage(int *arr, int size)
{
    // Accumulator
    double average = 0, total = 0;
    
    for (int count = 0; count < size; count++)
        total += *(arr + count);
        for (int count = 0; count < size; count++)
            average = total / size;
    cout << "\nThe average for " << size << " test scores are: "
    << average << "\n";
    
    return average;
}

// Display the sorted array
void ShowArray(const int *arr, int size)
{
    cout << "\nHere are the sorted test scores:\n";
    for (int counter = 0; counter < size; counter++)
    cout << *(arr + counter) << " ";
    cout << endl;
}

/*
 Here is the output for Test Scores #1, before I tried to modify for
 Test Scores #2. I couldn't figure out how to create a string array
 to hold user input names; therefore, I couldn't pass an array
 to the modified sort function to assign names to the test scores, 
 as stated in Test #2. Also, I couldn't figure out how to include
 input validation. I tried several ways of using input validation
 (do-while loop, while loop, and if loop), but none worked. Every loop 
 I tried keep going on forever, so I got rid of it.
 
 Output:
 How many tests do you have?
 5
 Please enter the test scores or -1 to quit:
 Test 1: 100
 Test 2: 93
 Test 3: 89
 Test 4: 83
 Test 5: 92
 
 Enter the names of the students in order of tests you submitted:
 Lola Maria Steven Jackson Mike
 Lola scored 100
 Maria scored 93
 Steven scored 89
 Jackson scored 83
 Mike scored 92
 
 Here are the sorted test scores:
 83 89 92 93 100
 
 The average for 5 test scores are: 91.4
 Program ended with exit code: 0
*/
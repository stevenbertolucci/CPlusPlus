/* 
Author: Steven Bertolucci
Assignment: Project #3
Description:
A retail company must ﬁle a monthly sales tax report listing the sales for the month
and the amount of sales tax collected. Write a program that asks for the month, the
year, and the total amount collected at the cash register (that is, sales plus sales tax).
Assume the state sales tax is 7.25 percent and the county sales tax is 2 percent.

The program should display a report similar to:

Month: October 2013
--------------------
Total Collected: $ 26572.89
Sales: $ 24323.01
County Sales Tax: $ 501.38
State Sales Tax: $ 1002.75
Total Sales Tax: $ 1504.13 (not necessarily accurate numbers)

Created by Steven Bertolucci on 9/24/13.
Copyright (c) 2013 Steven Bertolucci. All rights reserved.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
    const double COUNTY_TAX = .02, STATE_TAX = .0725;
    float totalSalesTax, salesWithStateTax, salesWithCountyTax;
    double sales, totalCollected;
    string monthYear;
    
    // prompt
    cout << "Please enter month and year: ";
    getline(cin, monthYear);
    cout << "Please enter the total "
        << "amount of sales tax collected: ";
    cin >> sales;
    cout << "\n";
    
    // calculations
    salesWithStateTax = sales * STATE_TAX;
    salesWithCountyTax = sales * COUNTY_TAX;
    totalSalesTax = salesWithStateTax + salesWithCountyTax;
    totalCollected = sales + totalSalesTax;
    
    cout << "Month: " << monthYear << endl;
    cout << "---------------------\n";
    cout << setprecision(2) << fixed;
    cout << "Total Collected: $ " << totalCollected << endl;
    cout << "Sales: $ " << sales << endl;
    cout << "County Sales Tax: $ " << salesWithCountyTax << endl;
    cout << "State Sales Tax: $ " << salesWithStateTax << endl;
    cout << "Total Sales Tax: $ " << totalSalesTax << endl;
    
    return 0;
}


/*
 Output:
 Please enter month and year: October 2013
 Please enter the total amount of sales tax collected: 43212.42
 
 Month: October 2013
 ---------------------
 Total Collected: $ 47209.57
 Sales: $ 43212.42
 County Sales Tax: $ 864.25
 State Sales Tax: $ 3132.90
 Total Sales Tax: $ 3997.15
 */


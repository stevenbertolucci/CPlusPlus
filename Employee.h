/*
 Author: Steven Bertolucci
 Description: UML Design for Step 2 & 3
 
 Employee.h
 Employee
 
 Created by Steven Bertolucci on 4/23/14.
 Copyright (c) 2014 Steven Bertolucci. All rights reserved.
 */


/***********************************************/
/*                                             */
/*   THIS IS THE DERIVED CLASS FOR INVENTORY   */
/*                                             */
/***********************************************/

#ifndef Inventory_Employee_h
#define Inventory_Employee_h
#include "Inventory.h"
#include <string>
using namespace std;

// Constants for required work years
const int WORK_YEARS = 100;

class Employee : public Inventory {
private:
    string employeeName;
    int employeeID, age;
    
public:
    // Default Constructor
    Employee() : Inventory()
    {
        employeeName = "";
        employeeID = 0;
        age = 0;
    }
    
    void setEmployeeName(string name) {
        employeeName = name;
        Inventory::setDescription(employeeName);
    }
    
    void setEmployeeID (int ID) {
        employeeID = ID;
    }
    
    void setAge(int ag) {
        age = ag;
    }
    
    string getEmployeeName() const {
        return employeeName;
    }
    
    int getEmployeeID() const {
        return employeeID;
    }
    
    int getAge() const {
        return age;
    }
    
    virtual int getRemainingWorkYears() const;
    
};


#endif

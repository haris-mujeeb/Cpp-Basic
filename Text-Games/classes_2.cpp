/* Write a program that would print the information (name, year of joining, salary, address) 
of three employees by creating a class named 'Employee'. 

The output should be as follows:
Name        Year of joining        Address
Robert        1994        64C- WallsStreat
Sam        2000        68D- WallsStreat
John        1999        26B- WallsStreat 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Employee
{
private:
    string m_name;
    int m_year_of_joining;
    float m_salary;
    string m_address;

public:
    Employee(const string& name, int year_of_joining, float salary, const string& address);
//     ~Employee();
    void getInfo();
    void AddSal();
    void AddWork();
    // static int s_count;
};

Employee::Employee(const string& name = "John Doe", int year_of_joining = 0, float salary = 0, const string& address = "X"):
    m_name(name),
    m_year_of_joining(year_of_joining),
    m_salary(salary),
    m_address(address)
    {
        // s_count++;      <-----------!!!!!!!!!!!!!!!!!!!!
    }

// Employee::~Employee()
// {
// }

void Employee::getInfo()
{
    cout << m_name << " | " << m_year_of_joining << " | " << m_address << " | " << m_salary ; 
}

void Employee::AddSal()
{
    if (m_salary < 500) this->m_salary += 10;
}


int main()
{
    // Employee Employee1("Robert", 1994, 1500 ,"64C");

    vector<Employee> employees;
    employees.reserve(3);
    employees.push_back(Employee("Robert", 1994, 350 ,"64C"));
    employees.push_back(Employee("Sam", 2000, 500 ,"68D"));
    employees.push_back(Employee("John", 1999, 400 ,"26B"));
    
    vector<Employee>::iterator iter; // using const_iterator so not to accidently change the element's value.
    
    // priting data using getInfo()
    cout << "Name" << " | " << "Year of Joining" << " | " << "Adress"<< " | " << "Salary" << endl; 
    for (iter = employees.begin(); iter != employees.end(); ++iter)
    {
        Employee emp = *iter;
        emp.getInfo();
        cout << endl;
    }

    // Adding Sallary $10 to the salary of the employee if it is less than $500.
    for (iter = employees.begin(); iter != employees.end(); ++iter)
    {
        (*iter).AddSal();
    }

    // priting data using getInfo()
    cout << "Name" << " | " << "Year of Joining" << " | " << "Adress"<< " | " << "Salary" << endl; 
    for (iter = employees.begin(); iter != employees.end(); ++iter)
    {
        (*iter).getInfo();
        cout << endl;
    }
}

#include <iostream>
#include "Employee.h"
#include "professional.h"
#include "nonprofessional.h"

Employee::Employee(std::string name, int employeeId) : name(name), employeeId(employeeId) {}

std::string Employee::getName() const {
    return name;
}

int Employee::getEmployeeId() const {
    return employeeId;
}


Professional::Professional(std::string name, int employeeId, double monthlySalary, int vacationDays)
    : Employee(name, employeeId), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

double Professional::calculateWeeklySalary() const {
    // Assuming a month has 4 weeks
    return monthlySalary / 4;
}

double Professional::calculateHealthCareContributions() const {
    // Example: 10% of monthly salary
    return 0.10 * monthlySalary;
}

int Professional::calculateVacationDays() const {
    return vacationDays;
}



Nonprofessional::Nonprofessional(std::string name, int employeeId, double hourlyRate, int hoursWorked)
    : Employee(name, employeeId), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

double Nonprofessional::calculateWeeklySalary() const {
    return hourlyRate * hoursWorked;
}

double Nonprofessional::calculateHealthCareContributions() const {
    // Example: 5% of weekly salary
    return 0.05 * calculateWeeklySalary();
}

int Nonprofessional::calculateVacationDays() const {
    // Example: 1 vacation hour for every 40 hours worked
    return hoursWorked / 40;
}


int main() {
    // Create instances of Professional and Nonprofessional employees
    Professional profEmployee("Janice Port", 1010, 10000.0, 15); // (name, employee id, monthly salary, vacation days)
    Nonprofessional nonprofEmployee("Johnny Graham", 1529, 12.0, 160);// (name, employee id, hourly rate, hours worked)

    // Calculate and display information
    std::cout << "Professional Employee Details:" << std::endl;
    std::cout << "Name: " << profEmployee.getName() << std::endl;
    std::cout << "Employee ID: " << profEmployee.getEmployeeId() << std::endl;
    std::cout << "Weekly Salary: $" << profEmployee.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << profEmployee.calculateHealthCareContributions() << std::endl;
    std::cout << "Vacation Days Earned: " << profEmployee.calculateVacationDays() << std::endl;

    std::cout << std::endl;

    std::cout << "Nonprofessional Employee Details:" << std::endl;
    std::cout << "Name: " << nonprofEmployee.getName() << std::endl;
    std::cout << "Employee ID: " << nonprofEmployee.getEmployeeId() << std::endl;
    std::cout << "Weekly Salary: $" << nonprofEmployee.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: $" << nonprofEmployee.calculateHealthCareContributions() << std::endl;
    std::cout << "Vacation Days Earned: " << nonprofEmployee.calculateVacationDays() << std::endl;

    return 0;
}
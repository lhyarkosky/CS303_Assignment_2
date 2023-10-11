#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
    Employee(std::string name, int employeeId);

    // Pure virtual function for calculating weekly salary
    virtual double calculateWeeklySalary() const = 0;

    // Pure virtual function for computing health care contributions
    virtual double calculateHealthCareContributions() const = 0;

    // Pure virtual function for computing vacation days earned
    virtual int calculateVacationDays() const = 0;

    // Getter functions
    std::string getName() const;
    int getEmployeeId() const;

private:
    std::string name;
    int employeeId;
};

#endif
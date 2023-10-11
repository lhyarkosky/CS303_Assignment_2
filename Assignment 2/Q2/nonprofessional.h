#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H

#include "Employee.h"

class Nonprofessional : public Employee {
public:
    Nonprofessional(std::string name, int employeeId, double hourlyRate, int hoursWorked);

    // Implement virtual functions
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;

private:
    double hourlyRate;
    int hoursWorked;
};

#endif
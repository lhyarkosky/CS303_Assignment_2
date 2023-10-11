#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "Employee.h"

class Professional : public Employee {
public:
    Professional(std::string name, int employeeId, double monthlySalary, int vacationDays);

    // Implement virtual functions
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;

private:
    double monthlySalary;
    int vacationDays;
};

#endif
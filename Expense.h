#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Expense {
public:
    Expense(int, int, int, std::string&, double);

    void setMonth(int);
    void setDay(int);
    void setYear(int);
    void setItem(std::string&);
    void setAmount(double);
    void setNext(Expense*);

    int getMonth() const;
    int getDay() const;
    int getYear() const;
    std::string getItem() const;
    double getAmount() const;
    Expense* getNext() const;

    bool operator<(const Expense&) const;

    void display() const;

private:
    int month;
    int day;
    int year;
    std::string item;
    double amount;

    Expense* next;
};

#endif

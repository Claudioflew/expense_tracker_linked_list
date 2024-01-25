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

    // Need this overloaded op as we want to sort Expense entries in chronological order
    bool operator<(const Expense&) const;

    void display() const;

private:
    int month{1};
    int day{1};
    int year{2000};
    std::string item{"item"};
    double amount{10.00};

    Expense* next;
};

#endif

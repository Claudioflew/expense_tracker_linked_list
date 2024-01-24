#include "Expense.h"

using namespace std;

Expense::Expense(int month, int day, int year, std::string& item, double amount) {
    setMonth(month);
    setDay(day);
    setYear(year);
    setItem(item);
    setAmount(amount);
    setNext(nullptr);
}

void Expense::setMonth(int month) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    } else {
        cout << "Invalid month.." << endl;
    }
}

void Expense::setDay(int day) {
    if (day >= 1 && day <= 31) {
        this->day = day;
    } else {
        cout << "Invalid day.." << endl;
    }
}

void Expense::setYear(int year) {
    if (year >= 2000 && day <= 2024) {
        this->year = year;
    } else {
        cout << "Invalid year.." << endl;
    }
}

void Expense::setItem(std::string& item) { this->item = item; }
void Expense::setAmount(double amount) { this->amount = amount; }
void Expense::setNext(Expense* expensePtr) { next = expensePtr; }

int Expense::getMonth() const { return month; }
int Expense::getDay() const { return day; }
int Expense::getYear() const { return year; }
string Expense::getItem() const { return item; }
double Expense::getAmount() const { return amount; }
Expense* Expense::getNext() const { return next; }

bool Expense::operator<(const Expense& other) const {
    if (year > other.year) return false;
    else if (year == other.year) {
        if (month > other.month) return false;
        else if (month == other.month) {
            if (day >= other.day) return false;
        }
    }
    return true;
}

void Expense::display() const {
    stringstream outputStream;
    outputStream << fixed << setprecision(2);

    string dateStr = to_string(getMonth()) + "-" + to_string(getDay()) + "-" + to_string(getYear());
    outputStream << "\nDate: " << dateStr;
    outputStream << "\nItem: " << getItem();
    outputStream << "\nAmount: " << getAmount();
    cout << outputStream.str() << endl;
}
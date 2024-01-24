#ifndef EXPENSELINKEDLIST_H
#define EXPENSELINKEDLIST_H

#include <iostream>
#include <sstream>
#include "Expense.h"

class ExpenseLinkedList {
public:
    ExpenseLinkedList();

    void insertExpense();
    void searchExpense() const;
    void deleteExpense();
    void displayAll() const;

private:
    Expense* head;

    Expense* makeExpensePtr();
    bool isEmpty() const;
    bool isOnlyOne() const;
};


#endif

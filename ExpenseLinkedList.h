#ifndef EXPENSELINKEDLIST_H
#define EXPENSELINKEDLIST_H

#include <iostream>
#include <sstream>
#include "Expense.h"

class ExpenseLinkedList {
public:
    ExpenseLinkedList();
    ~ExpenseLinkedList();

    void insertExpense();
    void insert(Expense*);
    void searchExpense() const;
    void deleteExpense();
    void displayAll() const;

private:
    Expense* head;

    // Helper functions
    Expense* makeExpensePtr();
    bool isEmpty() const;
    bool isOnlyOne() const;
};


#endif

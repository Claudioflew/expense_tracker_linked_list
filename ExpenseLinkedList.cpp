#include "ExpenseLinkedList.h"

using namespace std;

ExpenseLinkedList::ExpenseLinkedList() : head{nullptr} {}

void ExpenseLinkedList::insertExpense() {
    Expense* expensePtr = makeExpensePtr();

    if (isEmpty()) {
        head = expensePtr;
        cout << "\nItem inserted!" << endl;
        expensePtr->display();
        return;
    }
    if (isOnlyOne()) {
        if (*expensePtr < *head) {
            head->setNext(expensePtr);
            return;
        } else {
            expensePtr->setNext(head);
            head = expensePtr;
            return;
        }
    }

    Expense* prev = head;
    Expense* curr = head->getNext();
    while (curr != nullptr) {
        if (*curr < *expensePtr) break;
        prev = curr;
        curr = curr->getNext();
    }
    expensePtr->setNext(curr);
    prev->setNext(expensePtr);
    cout << "\nItem inserted!" << endl;
    expensePtr->display();
}

void ExpenseLinkedList::searchExpense() const {
    if (isEmpty()) {
        cout << "\nThe tracker is empty.." << endl;
        return;
    }

    string input;
    double amount;
    cout << "\nPlease input amount of the item to be searched: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> amount) break;
        cout << "Invalid entry.. Please enter a floating number: ";
    }

    Expense* curr = head;
    while (curr != nullptr) {
        if (curr->getAmount() == amount) {
            cout << "\nFound item:" << endl;
            curr->display();
            return;
        }
        curr = curr->getNext();
    }
    cout << "\nCouldn't find the item.." << endl;
}

void ExpenseLinkedList::deleteExpense() {
    if (isEmpty()) {
        cout << "\nThe tracker is empty.." << endl;
        return;
    }

    string input;
    double amount;
    cout << "\nPlease input amount of the item to be deleted: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> amount) break;
        cout << "Invalid entry.. Please enter a floating number: ";
    }

    Expense* prev = nullptr;
    Expense* curr = head;
    while(curr != nullptr) {
        if (curr->getAmount() == amount) {
            prev->setNext(curr->getNext());
            cout << "\nDeleted item:" << endl;
            curr->display();
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
    cout << "\nCouldn't find the item.." << endl;
}

void ExpenseLinkedList::displayAll() const {
    if (isEmpty()) {
        cout << "\nThe tracker is empty.." << endl;
        return;
    }

    Expense* curr = head;
    while (curr != nullptr) {
        curr->display();
        curr = curr->getNext();
    }
}

Expense* ExpenseLinkedList::makeExpensePtr() {
    int month, day, year;
    string item;
    double amount;

    string input;
    cout << "\nPlease enter month: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> month) break;
        cout << "Invalid entry.. Please enter an integer: ";
    }
    cout << "Please enter day: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> day) break;
        cout << "Invalid entry.. Please enter an integer: ";
    }
    cout << "Please enter year: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> year) break;
        cout << "Invalid entry.. Please enter an integer: ";
    }
    cout << "Please enter item name: ";
    getline(cin, item);

    cout << "Please enter amount: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> amount) break;
        cout << "Invalid entry.. Please enter a floating number: ";
    }

    Expense* expensePtr = new Expense(month, day, year, item, amount);
    return expensePtr;
}

bool ExpenseLinkedList::isEmpty() const {
    if (head == nullptr) return true;
    return false;
}

bool ExpenseLinkedList::isOnlyOne() const {
    if (head->getNext() == nullptr) return true;
    return false;
}
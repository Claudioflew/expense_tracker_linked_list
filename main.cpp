#include <iostream>
#include <sstream>
#include "ExpenseLinkedList.h"

using namespace std;

int chooseMenu();

int main() {
    ExpenseLinkedList list;

    int choice = chooseMenu();
    while (choice != 5) {
        switch (choice) {
            case 1 : list.insertExpense(); break;
            case 2 : list.searchExpense(); break;
            case 3 : list.deleteExpense(); break;
            case 4 : list.displayAll(); break;
        }
        choice = chooseMenu();
    }
    cout << "Thank you for using this program. Have a superior day!" << endl;
}

int chooseMenu() {
    int choice;
    string input;
    cout << "\nWelcome to Expense Tracker! How can I help you?" << endl;
    cout << "\n  1: Insert item\n  2: Search item\n  3: Delete item"
            "\n  4: Display all\n  5: Quit\n\nPlease enter your choice in number: ";
    while (true) {
        getline(cin, input);
        stringstream convert(input);
        if (convert >> choice && choice >= 1 && choice <= 5) break;
        cout << "Invalid entry.. Please enter a valid number: ";
    }
    return choice;
}

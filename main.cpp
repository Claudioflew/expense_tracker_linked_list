#include <iostream>
#include <fstream>
#include <sstream>
#include "Expense.h"
#include "ExpenseLinkedList.h"


using namespace std;

void readInitialData(string&, ExpenseLinkedList&);
int chooseMenu();

int main() {
    ExpenseLinkedList list;
    string filePath = "/Users/claudio/Desktop/School/CS/LMC/COMSC210_DataStructure/Lab_Assignments/Lab1_ExpenseTrackerLinkedList/InitialData.txt";
    readInitialData(filePath, list);

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

void readInitialData(string& filePath, ExpenseLinkedList& list) {
    fstream inputFile(filePath, ios::in);

    if (inputFile.is_open()) {
        int month, day, year;
        string item;
        double amount;

        inputFile >> month;
        while (!inputFile.eof()) {
            inputFile >> day >> year >> item >> amount;
            Expense* expensePtr = new Expense(month, day, year, item, amount);
            list.insert(expensePtr);
            inputFile >> month;
        }
    }
    inputFile.close();
}

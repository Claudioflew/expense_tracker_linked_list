cmake_minimum_required(VERSION 3.27)
project(Lab1_ExpenseTrackerLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1_ExpenseTrackerLinkedList main.cpp
        Expense.cpp
        Expense.h
        ExpenseLinkedList.cpp
        ExpenseLinkedList.h)

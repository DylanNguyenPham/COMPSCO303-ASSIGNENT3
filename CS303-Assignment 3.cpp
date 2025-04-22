// CS303-Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Queue.h"
#include <iostream>
#include "Function.h"
using namespace std;
int main()
{
    Queue<int> q;
    q.empty();
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    else {
        std::cout << "Queue is not empty" << std::endl;
    }
    //  Push 10 integers
    for (int i = 1; i <= 10; ++i) {
        q.push(i * 10);
    }

    //  Display all elements
    cout << "Initial Queue: ";
    q.display();

    // push, pop, front, empty
    // Push
    cout << "Queue push: ";
    q.push(11);
    q.display();
    cout << "Queue pop: ";
    q.pop();
    q.display();
    cout << "Queue front: ";
    q.front();

    //  Move front element to rear
    q.move_to_rear();

    cout << "move to rear: ";
    q.display();

    q.empty();
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    else {
        std::cout << "Queue is not empty" << std::endl;
    }
    list<int> nums = { 5, 2, 9, 1, 5, 6 };
    cout << "Before insertion sort (list): ";
    print_list(nums);
    insertion_sort(nums);
    cout << "After insertion sort (list): ";
    print_list(nums);
    cout << endl;

    // Test linear_search
    vector<int> vec = { 1, 2, 3, 2, 4 };
    int target = 2;
    cout << "Vector before linear search: ";
    print_vector(vec);
    int pos = linear_search(vec, target, 0);
    cout << "Last occurrence of " << target << " is at index: " << pos << endl;

    return 0;
}


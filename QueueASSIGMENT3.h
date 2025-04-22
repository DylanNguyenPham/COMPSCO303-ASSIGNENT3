#pragma once
#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T new_data) {
        data = new_data;
        next = nullptr;
    }
};

template<typename T>
class Queue {
private:
    Node<T>* frontPtr;
    Node<T>* rearPtr;
    int num_items;

public:
    Queue() {
        frontPtr = nullptr;
        rearPtr = nullptr;
        num_items = 0;
    }

    bool empty() {
        if (frontPtr == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        num_items++;
    }

    void pop() {
        if (!empty()) {
            Node<T>* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            num_items--;
            if (frontPtr == nullptr) {
                rearPtr = nullptr;  
            }
        }
    }

    T front() {
        if (!empty()) {
            return frontPtr->data;
        }
        throw std::out_of_range("Queue is empty");
    }

    T size() const {
        return num_items;
    }

    void move_to_rear() {
        if (!empty() && size() > 1) {
            T temp = front();  // get front element
            pop();             // remove it
            push(temp);        // push it to rear
        }
    }

    void display() {
        int count = size();
        for (int i = 0; i < count; ++i) {
            T val = front();
            std::cout << val << " ";
            pop();
            push(val);  
        }
        std::cout << std::endl;
    }
};
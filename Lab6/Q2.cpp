#include <iostream>
#include <chrono> // include chrono library for time measurement

using namespace std;
using namespace chrono; // use chrono library namespace

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // return -1 to indicate error
        }
        else {
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << "Popped " << x << " from the stack." << endl;
            return x;
        }
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // return -1 to indicate error
        }
        else {
            return top->data;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    auto start = high_resolution_clock::now(); // start time measurement

    // push elements onto the stack
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto stop = high_resolution_clock::now(); // stop time measurement
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration
    cout << "Time taken by all operations: " << duration.count() << " microseconds." << endl; // print duration in microseconds

    // get the top element of the stack
    cout << "Top of the stack: " << s.stackTop() << endl;

    return 0;
}


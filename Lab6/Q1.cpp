
#include <iostream>
#include <chrono>

using namespace std;

const int MAX_SIZE = 100; // maximum size of the stack

int top = -1; // initialize top to -1 to indicate an empty stack
int stack_arr[MAX_SIZE]; // create an empty array of fixed size

void Push(int data){
    if (top == MAX_SIZE-1){
        cout << "Stack Overflow!" << endl;
    }
    else{
        top++;
        stack_arr[top] = data;
    }
}

int Pop() {
    if (top < 0) {
        cout << "Stack Underflow!" << endl;
        return -1; // return -1 to indicate error
    }
    else {
        int x = stack_arr[top];
        top--;
        cout << "Popped " << x << " from the stack." << endl;
        return x;
    }
}

bool isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull() {
    if (top == MAX_SIZE-1) {
        return true;
    }
    else {
        return false;
    }
}

int StackTop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1; // return -1 to indicate error
    }
    else {
        return stack_arr[top];
    }
}

void Display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    }
    else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack_arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    cout << "Is the stack empty? " << boolalpha << isEmpty() << endl;
    cout << "Is the stack full? " << boolalpha << isFull() << endl;
    cout << "Top element of the stack: " << StackTop() << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by the operations: " << duration.count() << " microseconds" << endl;

    return 0;
}




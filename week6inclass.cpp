#include <iostream>
#include <ctime>

using namespace std;

// Stack using Array
class ArrayStack {
private:
    int capacity; // maximum size of the stack
    int* arr; // array to store elements of the stack
    int top; // index of the top element in the stack
public:
    ArrayStack(int capacity = 100) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }
    ~ArrayStack() {
        delete[] arr;
    }
    bool push(int x) {
        if (top == capacity - 1) {
            return false; // stack overflow
        }
        top++;
        arr[top] = x;
        return true;
    }
    bool pop() {
        if (top == -1) {
            return false; // stack underflow
        }
        top--;
        return true;
    }
    int peek() {
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
    int size() {
        return top + 1;
    }
};

// Stack using Linked List
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class ListStack {
private:
    Node* top;
    int sz;
public:
    ListStack() {
        top = nullptr;
        sz = 0;
    }
    ~ListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    bool push(int x) {
        Node* node = new Node(x);
        node->next = top;
        top = node;
        sz++;
        return true;
    }
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        sz--;
        return true;
    }
    int peek() {
        return top->val;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    int size() {
        return sz;
    }
};

int main() {
    ArrayStack arr_stack;
    ListStack list_stack;

    // push elements to the stack and measure the time taken
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        arr_stack.push(rand() % 100);
    }
    cout << "Time taken for pushing 1 million elements to array stack: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 1000000; i++) {
        list_stack.push(rand() % 100);
    }
    cout << "Time taken for pushing 1 million elements to linked list stack: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    // pop elements from the stack and measure the time taken
    start = clock();
    for (int i = 0; i < 500000; i++) {
        arr_stack.pop();
    }
    cout << "Time taken for popping 500000 elements from array stack: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 500000; i++) {
        list_stack.pop();
    }
    cout << "Time taken for popping 500000 elements from linked list stack: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
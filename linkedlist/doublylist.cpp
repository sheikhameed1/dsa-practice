#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() : head(nullptr), tail(nullptr) {}

    void push_front(int val) {

        if(head == nullptr) {
            head = tail = new Node(val);
        } else {
            head->prev = new Node(val);
            Node* temp = head;
            head = head->prev;
            head->next = temp;
        }
    }

    void push_back(int val) {

        if(tail == nullptr) {
            head = tail = new Node(val);
        } else {
            tail->next = new Node(val);
            Node* temp = tail;
            tail = tail->next;
            tail->prev = temp;
        }
    }

    void pop_front() {

        Node* temp = head;
        if(head == tail) {
            head = tail = nullptr;
            delete temp;
        } else {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void pop_back() {
        Node* temp = tail;
        if(head == tail) {
            head = tail = nullptr;
            delete temp;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    void printlist() {
        
        if(head == nullptr) {
            cout << "List is empty!";
            return;
        }
        Node* temp = head;
        cout << "Null <-> ";
        while(temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main() {

    return 0;
}
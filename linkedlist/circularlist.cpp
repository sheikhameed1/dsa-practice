#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
    
};

class CircularList {
public:
    Node* head;
    Node* tail;
    
    CircularList() : head(nullptr), tail(nullptr) {}

    void insert_at_head(int val) {
        
        Node* newNode = new Node(val);
        if(head == nullptr) {         // tail == nullptr
            head = tail = newNode;    
            tail->next = head;
        }
        else {
            newNode->next = head;  // newNode->next = tail->next;
            head = newNode;        // tail->next = newNode;
            tail->next = head;
        }
    }

    void insert_at_tail(int val) {

        Node* newNode = new Node(val);
        if(tail == nullptr) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            newNode->next = head; // newNode->next = tail->next
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_at_head() {

        Node* temp = head;
        if(head == tail) {
            head = tail = nullptr;
            delete temp;
        }
        else {
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void delete_at_tail() {

        Node* temp = head;
        if(head == tail) {
            head = tail = nullptr;
            delete temp;
        }
        else {
            while(temp->next != tail) {
            temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            tail->next = head;
            delete temp;
        }

    }
    void print() {
        
        if(head == nullptr) {
            cout << "List is empty!";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while(temp != head);

        cout << temp->data << endl;
    }
};

int main() {

    return 0;
}
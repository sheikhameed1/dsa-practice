#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class List {
private:
    Node* head;
    Node* tail;
public:
    List() : head(NULL), tail(NULL) {}

    void push_front(int val) { // O(1)
        Node* newNode = new Node(val); // dynamic
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head; // (*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val) {   // O(1)
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {     // O(1)
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {   // O(n)
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {     //O(n)
        if(pos < 0) {
            cout << "Invalid pos!\n";
            return;
        }
        if(pos == 0) {
            push_front(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i < pos-1; i++) {
            if(temp == NULL) {
                cout << "Invalid pos!\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int target) {   // O(n)
        Node* temp = head;
        for(int i = 0; temp != NULL; i++) {
            if(temp->data == target) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    void printLL() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);
    
    ll.insert(6,2);

    cout << ll.search(99);
    return 0;
}
#include <iostream>
using namespace std;

class Notification {
protected:                       // children can use it, main cannot
    char* data;

public:
    Notification() : data(nullptr) {}     // always starts in a defined state

    virtual ~Notification() {
        cout << "Notification destructor\n";
    }

    virtual void send() const {
        cout << "This is a notification.\n";    
    }
};

class EmailNotification : public Notification {
public:
    EmailNotification() {
        data = new char[200];
    }
    ~EmailNotification() override {
        delete[] data;
        cout << "Email destructor\n";
    }
    void send() const override {
        cout << "You received an Email\n";
    }
};

class SMSNotification : public Notification {
public:
    SMSNotification() {
        data = new char[100];
    }
    ~SMSNotification() override {
        delete[] data;
        cout << "SMS destructor\n";
    }
    void send() const override {
        cout << "You received an SMS\n";
    }
};

int main() {
    const int COUNT = 5;
    Notification* notifications[COUNT] = {
        new EmailNotification(),
        new SMSNotification(),
        new EmailNotification(),
        new SMSNotification(),
        new EmailNotification()
    };

    for (Notification* n : notifications) {
        n->send();
    }

    for (int i = 0; i < COUNT; i++) {
        delete notifications[i];      // you decide when destruction happens
    }

    return 0;
}
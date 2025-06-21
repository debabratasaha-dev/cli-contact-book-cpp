#pragma once

#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact (string name, string phone, string email = "null") {
        this->name = name;
        this->phone = phone;
        this->email = email;
    }
    void print() const {
        cout << "Name: " << name << ", Phone: " << phone;
        if (email != "null") {
            cout << ", Email: " << email;
        }
        cout << '\n';
    }
    bool operator<(const Contact& other) {
        return name < other.name;
    }
};
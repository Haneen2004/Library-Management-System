#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    string name;
    int id;
public:
    User(string name, int id) : name(name), id(id) {}
    virtual void displayInfo() const {
        cout << "User: " << name << " (ID: " << id << ")" << '\n';
    }
    virtual ~User() {}
};


class Member : public User {
public:
    Member(string name, int id) : User(name, id) {}
    void displayInfo() const override {
        cout << "Member: " << name << " (ID: " << id << ")" << endl;
    }
};


class Librarian : public User {
public:
    Librarian(string name, int id) : User(name, id) {}
    void displayInfo() const override {
        cout << "Librarian: " << name << " (ID: " << id << ")" << endl;
    }
};

#endif // USER_H

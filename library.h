#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <unordered_map>
#include <queue>

class Library {
private:
    unordered_map<string, Book> books;
    queue<string> waitList;
public:
    void addBook(const Book& book) {
        books[book.getTitle()] = book;
    }

    void removeBook(const string& title) {
        if (books.erase(title))
            cout << "Book removed successfully!" << endl;
        else
            cout << "Book not found!" << endl;
    }

    void borrowBook(const string& title) {
        if (books.find(title) != books.end()) {
            books[title].borrowBook();
        }
        else {
            cout << "Book not found!" << endl;
        }
    }

    void returnBook(const string& title) {
        if (books.find(title) != books.end()) {
            books[title].returnBook();
        }
        else {
            cout << "Book not found!" << endl;
        }
    }

    void displayBooks() const {
        for (const auto& pair : books) {
            pair.second.displayBook();
        }
    }

    void rateBook(const string& title, double rating) {
        if (books.find(title) != books.end()) {
            books.at(title).rateBook(rating);
        }
        else {
            cout << "Book not found!" << endl;
        }
    }
};

#endif // LIBRARY_H

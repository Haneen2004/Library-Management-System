#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string title, author, category;
    int copies;
    vector<double> ratings;
public:
    Book() {
        title = author = category = "none";
        copies = 0;
    }
    Book(string title, string author, string category, int copies)
        : title(title), author(author), category(category), copies(copies) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getCategory() const { return category; }
    int getCopies() const { return copies; }

    void borrowBook() {
        if (copies > 0) {
            copies--;
            cout << "Book borrowed successfully!" << endl;
        }
        else {
            cout << "No copies available!" << endl;
        }
    }

    void returnBook() {
        copies++;
        cout << "Book returned successfully!" << endl;
    }

    void rateBook(double rating) {
        ratings.push_back(rating);
    }

    double getAverageRating() const {
        if (ratings.empty()) return 0;
        double sum = 0;
        for (double r : ratings) sum += r;
        return sum / (int) ratings.size();
    }

    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author
            << ", Category: " << category << ", Copies: " << copies
            << ", Avg Rating: " << getAverageRating() << endl;
    }
};

#endif // BOOK_H

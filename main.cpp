#include "Library.h"
#include "User.h"

void menu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Remove Book\n";
    cout << "3. Borrow Book\n";
    cout << "4. Return Book\n";
    cout << "5. Display Books\n";
    cout << "6. Rate a Book\n";
    cout << "7. Exit\n";
}

int main() {
    Library library;
    int choice;
    string title, author, category;
    int copies;
    double rating;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter title, author, category, copies: ";
            cin >> title >> author >> category >> copies;
            library.addBook(Book(title, author, category, copies));
            break;
        case 2:
            cout << "Enter book title to remove: ";
            cin >> title;
            library.removeBook(title);
            break;
        case 3:
            cout << "Enter book title to borrow: ";
            cin >> title;
            library.borrowBook(title);
            break;
        case 4:
            cout << "Enter book title to return: ";
            cin >> title;
            library.returnBook(title);
            break;
        case 5:
            library.displayBooks();
            break;
        case 6:
            cout << "Enter book title and rating (1-5): ";
            cin >> title >> rating;
            library.rateBook(title, rating);
            break;
        case 7:
            cout << "Exiting system..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

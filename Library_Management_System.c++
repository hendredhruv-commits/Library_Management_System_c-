#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Generic Library class using Class Template
template <class T>
class Library {
private:
    vector<T> books; // Using std::vector instead of fixed array

public:
    // Add a book
    void addBook(const T& book) {
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    // Display all books
    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << "\n----- Library Books -----\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". " << books[i] << "\n";
        }
    }

    // Search for a book
    void searchBook(const T& book) const {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i] == book) {
                cout << "Book found at position " << i + 1 << ".\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library<string> library;
    int choice = 0;
    string book;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Safe integer input handling
        if (!(cin >> choice)) {
            cin.clear(); // Clear error state flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 4.\n";
            continue;
        }

        // Clear remaining newline character from cin >> choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "Enter book name: ";
            getline(cin, book);

            if (book.empty()) {
                cout << "Book name cannot be empty!\n";
            } else {
                library.addBook(book);
            }
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            cout << "Enter book name to search: ";
            getline(cin, book);

            if (book.empty()) {
                cout << "Search string cannot be empty!\n";
            } else {
                library.searchBook(book);
            }
            break;

        case 4:
            cout << "Thank you for using Library Management System!\n";
            break;

        default:
            cout << "Invalid choice! Please enter 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}

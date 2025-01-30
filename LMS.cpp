#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool issued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->issued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;
        cout << "Enter book ID: ";
        cin >> id;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);

        Book newBook(id, title, author);
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "\nBook List:\n";
        for (const auto &book : books) {
            cout << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author;
            if (book.issued) {
                cout << " | Status: Issued\n";
            } else {
                cout << " | Status: Available\n";
            }
        }
    }

    void issueBook() {
        int id;
        cout << "Enter book ID to issue: ";
        cin >> id;

        bool found = false;
        for (auto &book : books) {
            if (book.id == id) {
                if (book.issued) {
                    cout << "This book is already issued.\n";
                } else {
                    book.issued = true;
                    cout << "Book issued successfully!\n";
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void returnBook() {
        int id;
        cout << "Enter book ID to return: ";
        cin >> id;

        bool found = false;
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.issued) {
                    cout << "This book was not issued.\n";
                } else {
                    book.issued = false;
                    cout << "Book returned successfully!\n";
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\nLibrary Management System Menu\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Issue Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    viewBooks();
                    break;
                case 3:
                    issueBook();
                    break;
                case 4:
                    returnBook();
                    break;
                case 5:
                    cout << "Exiting the system...\n";
                    break;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    Library library;
    library.menu();
    return 0;
}

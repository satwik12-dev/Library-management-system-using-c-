#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string &title, const string &author) {
        books.push_back(Book(title, author));
        cout << "Book added: " << title << " by " << author << endl;
    }

    void displayBooks() {
        cout << "Available Books: \n";
        for (const auto &book : books) {
            if (!book.isBorrowed) {
                cout << "Title: " << book.title << ", Author: " << book.author << endl;
            }
        }
    }

    void borrowBook(const string &title) {
        for (auto &book : books) {
            if (book.title == title && !book.isBorrowed) {
                book.isBorrowed = true;
                cout << "You borrowed: " << title << endl;
                return;
            }
        }
        cout << "Book not available for borrowing." << endl;
    }

    void returnBook(const  string &title) {
        for (auto &book : books) {
            if (book.title == title && book.isBorrowed) {
                book.isBorrowed = false;
                 cout << "You returned: " << title <<  endl;
                return;
            }
        }
         cout << "This book was not borrowed." <<  endl;
    }
};

int main() {
    Library library;
    library.addBook("1984", "George Orwell");
    library.addBook("To Kill a Mockingbird", "Harper Lee");

    int choice;
     string title;

    do {
         cout << "\n1. Display Books\n2. Borrow Book\n3. Return Book\n4. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                 cout << "Enter the title of the book to borrow: ";
                 cin.ignore(); // To clear the newline character from the input buffer
                 getline( cin, title);
                library.borrowBook(title);
                break;
            case 3:
                 cout << "Enter the title of the book to return: ";
                 cin.ignore();
                 getline( cin, title);
                library.returnBook(title);
                break;
            case 4:
                 cout << "Exiting...\n";
                break;
            default:
                 cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


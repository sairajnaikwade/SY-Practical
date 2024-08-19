#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to print a row in a table format
template <typename TO, typename T1, typename T2, typename T3, typename T4, typename T5>
void print_row(ostream& os, TO const& to, T1 const& t1, T2 const& t2, T3 const& t3, T4 const& t4, T5 const& t5) {
    os << "| " << setw(4) << to 
       << " | " << setw(10) << t1 
       << " | " << setw(10) << t2 
       << " | " << setw(15) << t3 
       << " | " << setw(7) << fixed << setprecision(2) << t4 
       << " | " << setw(7) << t5 
       << " |\n";
}

// Function to print a border for the table
void print_border(ostream& os) {
    os << "+------+------------+------------+---------------+---------+---------+\n";
}

class BookShop {
public:
    string book_name;
    string book_author;
    string book_publisher;
    int book_price;
    int book_copies;

    // Default constructor
    BookShop() : book_price(0), book_copies(0) {}

    // Method to add book details
    void add_book() {
        cout << "\t● Enter Book Name: ";
        cin.ignore(); // Clear the newline character left in the buffer
        getline(cin, book_name);
        cout << "\t● Enter Book Author: ";
        getline(cin, book_author);
        cout << "\t● Enter Book Publisher: ";
        getline(cin, book_publisher);
        cout << "\t● Enter Book Price: ";
        cin >> book_price;
        cout << "\t● Enter Book Copies: ";
        cin >> book_copies;
    }

    // Method to display book details
    void display_book(int indx) {
        print_row(cout, indx, book_name, book_author, book_publisher, book_price, book_copies);
    }

    // Method to check availability of the book
    bool check_availability(int required_copies) {
        return required_copies <= book_copies;
    }

    // Static method to search for a book in the list
    static int search_book(BookShop lot[], const string& book_title, const string& author_name, int lot_size) {
        for (int i = 0; i < lot_size; i++) {
            if (lot[i].book_author == author_name && lot[i].book_name == book_title) {
                return i;
            }
        }
        return -1; // Return -1 if book is not found
    }

    // Static method to handle book ordering
    static void order_book(BookShop lot[], int lot_size) {
        string book_title, author_name;
        int required_copies;

        cout << " 》Enter Book Name: ";
        cin.ignore(); // Clear the newline character left in the buffer
        getline(cin, book_title);
        cout << " 》Enter Book Author: ";
        getline(cin, author_name);

        int indx = search_book(lot, book_title, author_name, lot_size);

        if (indx != -1) {
            cout << " 》Enter Book Copies Required: ";
            cin >> required_copies;

            if (lot[indx].check_availability(required_copies)) {
                cout << " [ Order Successfully Placed !!! ]" << endl;
                lot[indx].book_copies -= required_copies;

                cout << "[ ORDER Details ]" << endl;
                print_border(cout);
                print_row(cout, "Sr.no", "Name", "Author", "Publisher", "Price", "Copies Left");
                print_border(cout);
                lot[indx].display_book(indx + 1);
                print_border(cout);
            } else {
                cout << "OUT OF STOCK!!!" << endl;
            }
        } else {
            cout << "BOOK UNAVAILABLE IN SHOP!!!" << endl;
        }
    }
};

int main() {
    BookShop lot[5]; // Array to store up to 5 books
    int lot_size = 0; // Number of books currently in the list
    int choice;

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. ADD Books" << endl;
        cout << "2. Order Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter Number of BOOKS (Max 5): ";
            cin >> lot_size;

            if (lot_size > 5) {
                cout << "You can only add up to 5 books." << endl;
                lot_size = 5;
            }

            for (int i = 0; i < lot_size; i++) {
                cout << "\n 》Enter Details of Book - " << i + 1 << " : " << endl;
                lot[i].add_book();
                cout << "\n";
            }
            break;
        }
        case 2: {
            if (lot_size == 0) {
                cout << "No books available. Please add books first." << endl;
            } else {
                BookShop::order_book(lot, lot_size);
            }
            break;
        }
        case 3: {
            if (lot_size == 0) {
                cout << "No books available." << endl;
            } else {
                print_border(cout);
                print_row(cout, "No", "Name", "Author", "Publisher", "Price", "Copies");
                print_border(cout);
                for (int i = 0; i < lot_size; i++) {
                    lot[i].display_book(i + 1);
                }
                print_border(cout);
            }
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

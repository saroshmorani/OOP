#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock_position;

public:
    Book(string author, string title, double price, string publisher, int stock_position)
        : author(author), title(title), price(price), publisher(publisher), stock_position(stock_position) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }

    bool checkAvailability() {
        cout << "Available" << endl;
        cout << "Enter the number of copies you want: ";

        int copies;
        while (!(cin >> copies) || copies <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a positive number: ";
        }

        if (stock_position >= copies) {
            cout << "Total cost: $" << price * copies << endl;
            stock_position -= copies;
            return true;
        } else {
            cout << "Not enough copies available." << endl;
            return false;
        }
    }
};

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << endl;
        return 1;
    }

    string t = toLower(argv[1]);
    string a = toLower(argv[2]);

    vector<Book> books = {
        Book("Rowling", "HarryPotter", 39.99, "Bloomsbury", 10),
        Book("Tolkien", "Hobbit", 29.99, "HarperCollins", 5),
        Book("Orwell", "1984", 19.99, "Secker&Warburg", 7)
    };

    bool found = false;
    for (auto& book : books) {
        if (toLower(book.getTitle()) == t && toLower(book.getAuthor()) == a) {
            found = true;
            book.checkAvailability();
            break;
        }
    }

    if (!found) {
        cout << "Book not available." << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    string isbn;
    string author;
    string publisher;

public:
    Book(string bookName, string isbn, string author, string publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() {
      return this->bookName;
    }
    string getISBN() {
      return this->isbn;
    }
    string getAuthor() {
      return this->author;
    }
    string getPublisher() {
      return this->publisher;
    }

    string getBookInfo() {
        return "Book Name: " + this->bookName + "\nISBN: " + this->isbn + "\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
    }
};

int main() {
    Book books[3] = {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "9780451524935", "George Orwell", "Signet Classics"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "Harper Perennial"),
       };

    for (int i=0; i<3; i++) {
        cout << "\nBook " << (i + 1) <<endl;
        cout << books[i].getBookInfo() << "\n";
    }
    return 0;
}

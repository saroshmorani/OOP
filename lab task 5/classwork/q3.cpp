#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(title), author(author), isbn(isbn) {}
    
    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
};

class Catalog {
private:
    Book* books[10];
    int count;
    
public:
    Catalog() : count(0) {}
    
    void addBook(Book* book) {
        if (count < 10) {
            books[count++] = book;
        }
    }
    
    Book* findBook(const std::string& isbn) {
        for (int i = 0; i < count; ++i) {
            if (books[i]->getISBN() == isbn) {
                return books[i];
            }
        }
        return nullptr;
    }
};

class Library {
private:
    std::string name;
    std::string address;
    Catalog catalog; 
    Book* books[10];
    int bookCount;
    
public:
    Library(std::string name, std::string address) : name(name), address(address), bookCount(0) {}
    
    void addBook(Book* book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
            catalog.addBook(book);
        }
    }
    
    void findBookInCatalog(const std::string& isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            std::cout << "Found book: " << book->getTitle() << " by " << book->getAuthor() << "\n";
        } else {
            std::cout << "Book not found.\n";
        }
    }
};

int main() {
    Library myLibrary("Frere Hall", "Saddar");
    
    Book book1("Kite Runner", "Khalid Hossieni", "123456");
    Book book2("Matilda", "Roald Dahl", "654321");
    
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    
    myLibrary.findBookInCatalog("123456");
    myLibrary.findBookInCatalog("000000");
    
    return 0;
}

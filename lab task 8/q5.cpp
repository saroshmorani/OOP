#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string date, string id, string pub)
        : title(t), publicationDate(date), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << "\n";
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    // Function overloading for searching
    bool search(string searchTitle) { return title == searchTitle; }
    bool search(string searchTitle, string searchAuthor) { return title == searchTitle && publisher == searchAuthor; }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string date, string id, string pub, string a, string isbn, int pages)
        : Media(t, date, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media {
    string director;
    double duration;
    double rating;

public:
    DVD(string t, string date, string id, string pub, string dir, double dur, double rat)
        : Media(t, date, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << "/10\n";
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string date, string id, string pub, string art, string gen, int tracks)
        : Media(t, date, id, pub), artist(art), genre(gen), numberOfTracks(tracks) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nGenre: " << genre << "\nTracks: " << numberOfTracks << "\n";
    }
};

int main() {
    Book book1("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "978-0743273565", 180);
    DVD dvd1("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd1("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", "Pop", 9);

    cout << "\nLibrary Catalog:\n";
    book1.displayInfo();
    cout << "\n";
    dvd1.displayInfo();
    cout << "\n";
    cd1.displayInfo();

    cout << "\nChecking out 'The Great Gatsby'...\n";
    book1.checkOut();

    cout << "\nReturning 'The Great Gatsby'...\n";
    book1.returnItem();

    return 0;
}


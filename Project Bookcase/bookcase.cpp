#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Book {
public:
    std::string title;
    std::string author;
    int isbn;

    Book(std::string title, std::string author, int isbn) : title(title), author(author), isbn(isbn) {}
};

class Shelf {
public:
    std::vector<Book> books;
    static int capacity;

    Shelf() {
        std::cout << "A shelf is being constructed." << std::endl;
    }

    ~Shelf() {
        std::cout << "A shelf is being destroyed." << std::endl;
    }

    bool placeBook(const Book& book) {
        if (books.size() < capacity) {
            books.push_back(book);
            std::cout << "Placing book: " << book.title << std::endl;
            return true;
        } else {
            std::cout << "Error: Shelf is full." << std::endl;
            return false;
        }
    }

    bool takeBook() {
        if (!books.empty()) {
            std::cout << "Taking book: " << books.back().title << std::endl;
            books.pop_back();
            return true;
        } else {
            std::cout << "Error: Shelf is empty." << std::endl;
            return false;
        }
    }

    void print() const {
        if (books.empty()) {
            std::cout << "Shelf is empty." << std::endl;
        } else {
            for (const auto& book : books) {
                std::cout << "Book: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << std::endl;
            }
        }
    }
};

int Shelf::capacity = 0;

class Cupboard {
public:
    Shelf topShelf;
    Shelf bottomShelf;

    Cupboard() {
        std::cout << "A cupboard is being constructed." << std::endl;
    }

    ~Cupboard() {
        std::cout << "A cupboard is being destroyed." << std::endl;
    }

    void print() const {
        std::cout << "Printing top shelf of the cupboard:" << std::endl;
        topShelf.print();
        std::cout << "Printing bottom shelf of the cupboard:" << std::endl;
        bottomShelf.print();
    }
};

class Base {
public:
    Base() {
        std::cout << "A base is being constructed." << std::endl;
    }

    ~Base() {
        std::cout << "A base is being destroyed." << std::endl;
    }
};

class Library {
public:
    Base base;
    Cupboard cupboard;
    Shelf topShelf;
    Shelf middleShelf;
    Shelf bottomShelf;

    Library() {
        std::cout << "A library is being constructed." << std::endl;
    }

    ~Library() {
        std::cout << "A library is being destroyed." << std::endl;
    }

    bool placeBook(int place, const Book& book) {
        switch (place) {
            case 1: return topShelf.placeBook(book);
            case 2: return middleShelf.placeBook(book);
            case 3: return bottomShelf.placeBook(book);
            case 4: return cupboard.topShelf.placeBook(book);
            case 5: return cupboard.bottomShelf.placeBook(book);
            default: std::cout << "Error: Invalid place." << std::endl; return false;
        }
    }

    bool takeBook(int place) {
        switch (place) {
            case 1: return topShelf.takeBook();
            case 2: return middleShelf.takeBook();
            case 3: return bottomShelf.takeBook();
            case 4: return cupboard.topShelf.takeBook();
            case 5: return cupboard.bottomShelf.takeBook();
            default: std::cout << "Error: Invalid place." << std::endl; return false;
        }
    }

    void print() const {
        std::cout << "Printing top shelf of the library:" << std::endl;
        topShelf.print();
        std::cout << "Printing middle shelf of the library:" << std::endl;
        middleShelf.print();
        std::cout << "Printing bottom shelf of the library:" << std::endl;
        bottomShelf.print();
        std::cout << "Printing the cupboard:" << std::endl;
        cupboard.print();
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Usage: " << argv[0] << " <NMax> <L> <K1> <K2>" << std::endl;
        return 1;
    }

    int NMax = std::stoi(argv[1]);
    int L = std::stoi(argv[2]);
    int K1 = std::stoi(argv[3]);
    int K2 = std::stoi(argv[4]);

    Shelf::capacity = NMax;

    Library library;

    std::srand(std::time(nullptr));

    // Create L books
    std::vector<Book> books;
    for (int i = 0; i < L; ++i) {
        books.push_back(Book("Book " + std::to_string(i), "Author " + std::to_string(i), i));
    }

    // Randomly place K1 books
    for (int i = 0; i < K1; ++i) {
        int place = std::rand() % 5 + 1;
        if (!books.empty()) {
            library.placeBook(place, books.back());
            books.pop_back();
        }
    }

    // Randomly take K2 books
    for (int i = 0; i < K2; ++i) {
        int place = std::rand() % 5 + 1;
        library.takeBook(place);
    }

    // Print library state
    library.print();

    return 0;
}

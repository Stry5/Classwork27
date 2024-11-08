#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

namespace books {
    // structures
    struct Author {
        std::string lastName;
        std::string firstName;
    };

    struct Date {
        short month;
        short day;
        short year;

    };

    struct Book {
        Author author;
        std::string title;
        Date publishDate;
        std::string genre;
        double price;
        short quantity;
    };
    // enumerations
    enum Actions {
        QUIT = 0,
        PRINT = 1,
        SEARCH = 2,
        ADD = 3,
        DISPLAY_MENU = 4

    };
    // operator overloads

    // compares all values in a book
    bool operator==(Book& book1, Book& book2) {
        return (
            (book1.title == book2.title) &&
            (book1.author.firstName == book2.author.firstName) &&
            (book1.author.lastName == book2.author.lastName) &&
            (book1.genre == book2.genre) &&
            (book1.price == book2.price) &&
            (book1.quantity == book2.quantity) &&
            (book1.publishDate.day == book2.publishDate.day) &&
            (book1.publishDate.month == book2.publishDate.month) &&
            (book1.publishDate.year == book2.publishDate.year));
    };
    bool operator!=(Book& book1, Book& book2) {
        return (
            (book1.title != book2.title) ||
            (book1.author.firstName != book2.author.firstName) ||
            (book1.author.lastName != book2.author.lastName) ||
            (book1.genre != book2.genre) ||
            (book1.price != book2.price) ||
            (book1.quantity != book2.quantity) ||
            (book1.publishDate.day != book2.publishDate.day) ||
            (book1.publishDate.month != book2.publishDate.month) ||
            (book1.publishDate.year != book2.publishDate.year));
    };

    std::ostream& operator<<(std::ostream& stream, Book& book) {
        return(stream << "----\n"
            << std::setw(18) << std::left << "Author: " << book.author.lastName << ", " << book.author.firstName << std::endl
            << std::setw(18) << std::left << "Title: " << book.title << std::endl
            << std::setw(18) << std::left << "Date Published: " << book.publishDate.month << "-"
            << book.publishDate.day << "-" << book.publishDate.year << std::endl
            << std::setw(18) << std::left << "Genre: " << book.genre << std::endl
            << std::setw(18) << std::left << "Price: " << book.price << std::endl
            << std::setw(18) << std::left << "Quantity: " << book.quantity);
    }



    // functions
    void displayMenu() {
        std::cout << "------\n"
            << std::setw(5) << std::left << "MENU:\n"
            << "------\n"
            << std::setw(20) << std::left << "Print List :" << std::setw(3) << std::right << "1\n"
            << std::setw(20) << std::left << "Search List :" << std::setw(3) << std::right << "2\n"
            << std::setw(20) << std::left << "Add to List :" << std::setw(3) << std::right << "3\n"
            << std::setw(20) << std::left << "Display this Menu :" << std::setw(3) << std::right << "4\n";
    }

    void printList(std::vector<Book>& list) {
        for (auto counter : list) {
            std::cout << counter << std::endl;
        }
    }

    //only have time for searching by title of the book, other methods would take too long
    void searchList(std::vector<Book>& list) {

        bool isFound = false; //boolean to check if the book has been found or not

        std::string querey;
        std::cout << "Please input the title of the book you're looking for\n";
        //first getline eats extra \n in the input buffer
        std::getline(std::cin, querey);

        std::getline(std::cin, querey);

        //searches list
        for (auto counter : list) {
            if (counter.title == querey) {
                std::cout << "Book found\n";
                std::cout << counter;
                isFound = true; //sets isFound to true
                //breaks early if the item is found
                break;
            }
        }
        // displays error message
        if (isFound == false) {
            std::cout << "Error. Book title not found.\n";
        }
    }

    void addItem(std::vector<Book>& list) {
        books::Book newBook;
        std::cout << "Please input the title of the book.\n";
        std::getline(std::cin, newBook.title);
        std::getline(std::cin, newBook.title);
        std::cout << "Please input the author's last name.\n";
        std::getline(std::cin, newBook.author.lastName);
        std::cout << "Please input the author's first name.\n";
        std::getline(std::cin, newBook.author.firstName);
        std::cout << "Please input the book's publishing month.\n";
        std::cin >> newBook.publishDate.month;
        std::cout << "Please input the book's publishing day.\n";
        std::cin >> newBook.publishDate.day;
        std::cout << "Please input the book's publishing year.\n";
        std::cin >> newBook.publishDate.year;
        std::cout << "Please input the book's genre.\n";
        std::getline(std::cin, newBook.genre);
        std::getline(std::cin, newBook.genre);
        std::cout << "Please input the book's price.\n";
        std::cin >> newBook.price;
        std::cout << "Please input the book's quantity.\n";
        std::cin >> newBook.quantity;

        list.push_back(newBook);
        std::cout << "Book added.\n";

    }

    // menu operation function
    void menuOperation(enum Actions& action, std::vector<Book>& list) {
        if (action != QUIT) {
            switch (action) {
            case QUIT:
                action = QUIT;
                break;
            case PRINT:
                printList(list);
                break;
            case SEARCH:
                searchList(list);
                break;
            case ADD:
                addItem(list);
                break;
            case DISPLAY_MENU:
                displayMenu();
                break;
            default:
                std::cout << "Error, that is not a valid input. Please try again.\n";
                break;
            }
        }
    }
};
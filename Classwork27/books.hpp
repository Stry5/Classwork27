#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

namespace books {
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
    enum Actions {
        QUIT,
        PRINT,
        SEARCH,
        ADD,
        DISPLAY_MENU

    };

  
    bool operator==(Book& book1, Book& book2);
    bool operator!=(Book& book1, Book& book2);
    std::ostream& operator<<(std::ostream& stream, Book& book);

    // functions
    void displayMenu();
    void printList(std::vector<Book>& list);
    void searchList(std::vector<Book>& list);
    void addItem(std::vector<Book>& list);
    void menuOperation(enum Actions& action, std::vector<Book>& list);


};
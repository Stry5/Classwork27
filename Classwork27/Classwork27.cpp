#include "books.hpp"

int main()
{
    //enum initialized
    enum books::Actions action = books::DISPLAY_MENU;
    int input;
    std::cout << "Welcome to the Book Inventory Management System\n";

    std::vector<books::Book> list;

    // creating test books, could be deleted later
    books::Book book1 = {{ "Poe","Edgar" }, "The Raven", { 01,29,1845 }, "Poetry", 9.99, 5};
    books::Book book2 = { { "Kibushi","Kazu" }, "Amulet: The Stonekeeper", { 01,01,2008 }, "Fiction", 4.99, 3 };
    books::Book book3 = { { "Weir","Andy" }, "The Martian", { 00,00,2011 }, "Science Fiction", 8.99, 2 };

    // adds books to the list
    list.push_back(book1);
    list.push_back(book2);
    list.push_back(book3);




    while (action != books::QUIT) {
        books::displayMenu();
        std::cout  << "Please input your option\n";

        std::cin >> input;


        // cast input to an enum, so action can read from input
        action = static_cast<books::Actions>(input);
        books::menuOperation(action,list);
    }

}

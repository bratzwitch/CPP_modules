#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (!std::cin) {
            std::cout << "\nBye\n";
            break;
        }
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}
#include "PhoneBook.hpp"

void PhoneBook::addContact() {
    std::cout << "Adding a new contact...\n";
    contacts[currentIndex].setContact();
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    std::cout << "Cool well played\n";
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < totalContacts; i++) {
        contacts[i].displayShort(i);
    }
    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    if (!std::cin)
        return;
    if (input.length() == 1 && std::isdigit(input[0])) {
        int index = input[0] - '0';
        if (index >= 0 && index < totalContacts) {
            contacts[index].displayFull();
            return;
        }
        else
            std::cout << "Invalid index!" << std::endl;
    }
    else {
        std::cout << "Invalid index!" << std::endl;
    }
}
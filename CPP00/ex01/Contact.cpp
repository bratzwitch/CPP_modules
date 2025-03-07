#include "Contact.hpp"

void Contact::setContact() {
    while (true) {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
        if (!std::cin)
            return;
        if (firstName.empty()) {
            std::cout << "No empty lines bro! Try again.\n";
            continue;
        }
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        if (!std::cin)
            return;
        if (lastName.empty()) {
            std::cout << "No empty lines bro! Try again.\n";
            continue;
        }
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);
        if (!std::cin)
            return;
        if (nickname.empty()) {
            std::cout << "No empty lines bro! Try again.\n";
            continue;
        }
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        if (!std::cin)
            return;
        if (phoneNumber.empty()) {
            std::cout << "No empty lines bro! Try again.\n";
            continue;
        }
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);
        if (!std::cin)
            return;
        if (darkestSecret.empty()) {
            std::cout << "No empty lines bro! Try again.\n";
            continue;
        }
        break;
    }
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
              << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
              << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
              << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n"
              << "Nickname: " << nickname << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "Darkest Secret: " << darkestSecret << "\n";
}
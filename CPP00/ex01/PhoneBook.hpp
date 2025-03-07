#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook() : currentIndex(0), totalContacts(0) {}
    void addContact();
    void searchContact() const;
};
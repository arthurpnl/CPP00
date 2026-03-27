#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contact[8];
    int _contactCount;
    
    std::string _getValidInput(std::string prompt);
    void _displayHeader(void);
    void _displayContact(int index);
    void _displayContactDetails(int index);

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(void);
    void search_contact(void);
};

#endif

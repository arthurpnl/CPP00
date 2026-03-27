#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string  truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

PhoneBook::PhoneBook()
{
    this->_contactCount = 0;
}

PhoneBook::~PhoneBook()
{

}

std::string PhoneBook::_getValidInput(std::string prompt)
{
    std::string input;
    
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Field cannot be empty!" << std::endl;
    } while (input.empty());
    
    return input;
}

void PhoneBook::add_contact(void)
{
    int index = this->_contactCount % 8;
    
    this->_contact[index].set_firstname(_getValidInput("First name: "));
    this->_contact[index].set_lastname(_getValidInput("Last name: "));
    this->_contact[index].set_nickname(_getValidInput("Nickname: "));
    this->_contact[index].set_phonenumber(_getValidInput("Phone number: "));
    this->_contact[index].set_secret(_getValidInput("Darkest secret: "));
    
    this->_contactCount++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::_displayHeader(void)
{
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::_displayContact(int index)
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncate(_contact[index].get_firstname()) << "|";
    std::cout << std::setw(10) << truncate(_contact[index].get_lname()) << "|";
    std::cout << std::setw(10) << truncate(_contact[index].get_nickname()) << std::endl;
}

void PhoneBook::_displayContactDetails(int index)
{
    std::cout << "\nFirst name: " << _contact[index].get_firstname() << std::endl;
    std::cout << "Last name: " << _contact[index].get_lname() << std::endl;
    std::cout << "Phone number: " << _contact[index].get_phonenumber() << std::endl;
    std::cout << "Nickname: " << _contact[index].get_nickname() << std::endl;
    std::cout << "Darkest secret: " << _contact[index].get_secret() << std::endl;
}

void PhoneBook::search_contact(void)
{
    if (_contactCount == 0)
    {
        std::cout << "No contacts found in the phonebook!" << std::endl;
        return;
    }
    
    int max;
    int index;

    index = -1; 
    if (_contactCount < 8)
        max = _contactCount;
    else
        max = 8;
    
    _displayHeader();
    for (int i = 0; i < max; i++)
        _displayContact(i);

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "\nEnter index: ";
    
    if (std::cin.peek() == '\n')
    {
        std::cout << "No index entered!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return ;
    }
    else if (!(std::cin >> index))
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return ;
    }
    else if (index >= 0 && index < max)
    {
        _displayContactDetails(index);
        std::cin.ignore(10000, '\n');
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid index!" << std::endl;
    }
}
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook phonebook;
    PhoneBook phonebook2;
    std::string command;
    
    std::cout << "=== MY AWESOME PHONEBOOK ===" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "> Enter command: ";
        std::getline(std::cin, command);
        
        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command! Use: ADD, SEARCH, or EXIT" << std::endl;
        }
    }
    
    return 0;
}
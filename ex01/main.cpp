/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:58:16 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 06:45:03 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*#include "PhoneBook.hpp"
#include "tools.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	std::string name;
	std::string last_name;
	std::string number;
	
	std::cout<<"\tEnter ADD, SEARCH or EXIT"<<std::endl;
	
	while(1)
	{
		std::cout<<"> ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			add_contact(name,last_name, number);
			phonebook.add_phone_book(name,last_name, number);
			continue;
		}
		else if (command == "SEARCH")
		{
			search_contact(phonebook);
			continue;
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout<<"command error"<<std::endl;
			continue ;
		}
		
	}
	
	
	return (0);
}*/

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "tools.hpp"

int main() 
{
    PhoneBook phonebook;
    std::string cmd;

    while (true) 
	{
        std::cout << "Enter a command (ADD | SEARCH | EXIT): ";
        if (!std::getline(std::cin, cmd)) {
            std::cout << std::endl; // EOF
            break;
        }

        if (cmd == "ADD") {
            Contact c = build_contact_interactively();
            // Si hubo EOF a mitad, build_contact_interactively() devuelve un Contact "vacío":
            if (c.is_empty()) {
                // Salimos silenciosamente si fue EOF; o simplemente no guardamos.
                continue;
            }
            phonebook.add_contact(c);
            std::cout << "Saved contact." << std::endl;
        }
        else if (cmd == "SEARCH") {
            phonebook.search_contact();
        }
        else if (cmd == "EXIT") {
            break;
        }
        else if (!cmd.empty()) {
            std::cout << "Unrecognized command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}

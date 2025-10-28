/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:58:16 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 20:30:29 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            if (c.is_empty()) 
			{

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

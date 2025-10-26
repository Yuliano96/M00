/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:58:16 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/26 15:40:00 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
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
}
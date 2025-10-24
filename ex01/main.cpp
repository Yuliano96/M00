/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:58:16 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/24 07:52:40 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"


void	add_contact(std::string &name, std::string &last_name, std::string &number)
{
	std::cout<<"enter the name : ";
	std::getline(std::cin, name);
	std::cout<<"enter last name: ";
	std::getline(std::cin, last_name);
	std::cout<<"enter the phone number: ";
	std::getline(std::cin, number);
	
}

int main()
{
	//std::string options[] = {"ADD","SEARCH", "EXIT"};
	//int length = sizeof(options) / sizeof(options[0]);
	PhoneBook phonebook;
	std::string command;
	std::string name;
	std::string last_name;
	std::string number;
	
	std::cout<<"\tEnter ADD, SEARCH or EXIT"<<std::endl;
	while(1)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			add_contact(name,last_name, number);
			phonebook.add_phone_book(name,last_name, number);
			continue;
		}
		if (command == "print")
		{
			int i = 0;
			while(i < Max_contact)
			{
				phonebook.print_contact(i);
				i++;
			}
			continue;
		}
		else
		{
			std::cout<<"command error"<<std::endl;
		}
		
	}
	
	
	return (0);
}
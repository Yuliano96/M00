/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:44:59 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/26 15:35:41 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.hpp"
#include <ctype.h>
#include "PhoneBook.hpp"

void clear_console()
{
    // Limpia la pantalla y coloca el cursor al inicio
    std::cout << "\033[2J\033[1;1H";
}



int str_isdigit(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int str_isalpha(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
			return (0);
	}
	return (1);
}

void	add_contact(std::string &name, std::string &last_name, std::string &number)
{

	while(name.empty() || !str_isalpha(name))
	{
		std::cout<<"enter the name : ";
		std::getline(std::cin, name);
	}		
	
	while(last_name.empty() || !str_isalpha(last_name))
	{
		std::cout<<"enter last name : ";
		std::getline(std::cin, last_name);
	}	
	
	while(number.empty() || !str_isdigit(number))
	{
		std::cout<<"enter the phone number: ";
		std::getline(std::cin, number);
	}	
	
}

void	search_contact(PhoneBook &phonebook)
{
	int i = 0;
	while(1)
	{
		std::cout<<"enter the index :";
		std::cin >> i;
		std::cin.ignore();
		if (i <= 0 || i > phonebook.get_size())
		{
			std::cout<<"incorrect index"<<std::endl;
			continue ;
		}
		else
			break;
	}
	phonebook.print_contact(i - 1);
}
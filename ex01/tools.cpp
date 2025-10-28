/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:44:59 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/28 07:13:48 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "tools.hpp"
#include <ctype.h>
#include "PhoneBook.hpp"


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
}*/

#include "tools.hpp"
#include <iostream>

bool is_all_digits_or_sign(const std::string &s) 
{
    if (s.empty())
		return false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (!(c == '+' || c == '-' || (c >= '0' && c <= '9')))
            return false;
    }
    return true;
}

bool number_of_digits(const std::string &s)
{
	if (s.size() != 9)
		return (false);
	return (true);
}

std::string prompt_non_empty(const std::string &label) 
{
    std::string s;
    while (true) 
	{
        std::cout << label;
        if (!std::getline(std::cin, s)) 
		{
            std::cout << std::endl; // EOF o error
            return "";
        }
        if (!s.empty())
			return s;
        std::cout << "The field cannot be empty. Please try again." << std::endl;
    }
}

bool is_valid_phone(const std::string &s) 
{
	if (is_all_digits_or_sign(s) && number_of_digits(s))
		return true;
	return false;
}

bool str_isalpha(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

Contact build_contact_interactively() 
{
    Contact c;
    std::string v;

	while(true)
	{
		v = prompt_non_empty("Name: ");
		if (v.empty())
			return Contact();
		if (str_isalpha(v)) break;
        std::cout << "invalid." << std::endl;
	}
    
    c.set_first_name(v);

    v = prompt_non_empty("Surnames: ");
    if (v.empty())
		return Contact();
    c.set_last_name(v);

    v = prompt_non_empty("Nickname: ");
    if (v.empty())
		return Contact();
    c.set_nickname(v);

    while (true) 
	{
        v = prompt_non_empty("Phone number: ");
        if (v.empty())
			return Contact();
        
        if (is_valid_phone(v)) break;
        std::cout << "Invalid phone number." << std::endl;
    }
    c.set_phone_number(v);

    v = prompt_non_empty("Darkest secret:");
    if (v.empty()) 
		return Contact();
    c.set_darkest_secret(v);

    return c;
}

bool read_index_in_range(const std::string &label, int min_val, int max_val, int &out_idx) 
{
    std::string line;
	
    while (true) 
	{
        std::cout << label;
        if (!std::getline(std::cin, line)) 
		{
            std::cout << std::endl; // EOF
            return false;
        }
        if (line.empty()) {
            std::cout << "Empty index." << std::endl;
            continue;
        }
		
        bool ok = true;
        int sign = 1;
        std::size_t i = 0;
        long val = 0;

        if (line[0] == '+' || line[0] == '-') { sign = (line[0] == '-') ? -1 : 1; i = 1; }
        if (i >= line.size()) ok = false;

        for (; ok && i < line.size(); ++i) 
		{
            if (line[i] < '0' || line[i] > '9') 
			{ 
				ok = false; 
				break; 
			}
            val = val * 10 + (line[i] - '0');
            if (val > 1000000) break; // evitar overflow tonto
        }
        if (!ok) {
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        val *= sign;
        if (val < min_val || val > max_val) {
            std::cout << "Index out of range (" << min_val << "-" << max_val << ")." << std::endl;
            continue;
        }
        out_idx = static_cast<int>(val);
        return true;
    }
}

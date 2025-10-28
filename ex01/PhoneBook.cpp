/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:44:23 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 20:30:51 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "tools.hpp"
#include <iostream>
#include <iomanip>

std::string shrink10(const std::string &s) 
{
    if (s.size() <= 10) return s;
    return s.substr(0, 9) + ".";
}

PhoneBook::PhoneBook() : size(0), next_index(0) {}


void PhoneBook::add_contact(const Contact &c) 
{
    contacts[next_index] = c;
    next_index = (next_index + 1) % MAX_contacts;
    if (size < MAX_contacts) 
		size++;
}

int PhoneBook::get_size() const 
{
    return size;
}

void PhoneBook::print_table() const 
{
    std::cout << std::setw(10) << "Index"   << "|"
              << std::setw(10) << "Name"    << "|"
              << std::setw(10) << "LastName"<< "|"
              << std::setw(10) << "Nickname"    << std::endl;

    for (int i = 0; i < size; ++i) 
	{
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << shrink10(contacts[i].get_first_name()) << "|"
                  << std::setw(10) << shrink10(contacts[i].get_last_name())  << "|"
                  << std::setw(10) << shrink10(contacts[i].get_nickname())   << std::endl;
    }
}

void PhoneBook::print_contact(int index) const 
{
	index = index - 1;
    if (index < 0 || index >= size) 
	{
        std::cout << "Index out of range." << std::endl;
        return;
    }

    std::cout << "Name:          " << contacts[index].get_first_name()    << std::endl;
    std::cout << "Surnames:      " << contacts[index].get_last_name()     << std::endl;
    std::cout << "Nickname:      " << contacts[index].get_nickname()      << std::endl;
    std::cout << "phone number:  " << contacts[index].get_phone_number()  << std::endl;
    std::cout << "Dark secret:   " << contacts[index].get_darkest_secret()<< std::endl;
}

void PhoneBook::search_contact() const 
{
    if (size == 0) 
	{
        std::cout << "There are no contacts saved."<< std::endl;
        return ;
    }
    print_table();

    int idx;
    if (!read_index_in_range("Index to display: ", 1, size, idx)) {
        // EOF o entrada abortada
        return ;
    }
    print_contact(idx);
}

PhoneBook::~PhoneBook() 
{
	
}
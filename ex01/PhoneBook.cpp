/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:44:23 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/26 13:17:25 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include<iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	index = 0;
	size = 0;
}

void PhoneBook::add_phone_book(const std::string &_name, const std::string &last_name,\
		const std::string &_number)
{
	contact[index].set_name(_name);
	contact[index].set_lastname(last_name);
	contact[index].set_number(_number);
	index = (index + 1) % Max_contact;
	if (size < Max_contact)
		size++;
}

int PhoneBook::get_index()
{
	return (index);
}

int PhoneBook::get_size()
{
	return (size);
}

void PhoneBook::print_contact(int index)
{
	std::string aux_name = contact[index].get_name();
	std::string aux_lastname = contact[index].get_last_name();
	std::string aux_number = contact[index].get_number();
	
	if (aux_name.size() >= 10)
		aux_name.insert(9, ".");
	if (aux_lastname.size() >= 10)
		aux_lastname.insert(9, ".");
	if(aux_number.size() >= 10)
		aux_number.insert(9, ".");
	
	std::cout << std::setw(10) << index + 1 <<"|";
	std::cout<<std::setw(10)<<aux_name.substr(0, 10)<<"|";
	std::cout<<std::setw(10)<<aux_lastname.substr(0, 10)<<"|";
	std::cout<<std::setw(10)<<aux_number.substr(0, 10)<<"|"<<std::endl;
}

PhoneBook::~PhoneBook()
{
	
}
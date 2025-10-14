/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:44:23 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/14 20:57:07 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include<iostream>
#include <cstring> // solo necesario si usas strcpy (opción B)

PhoneBook::PhoneBook()
{
	index = 0;
}

void PhoneBook::add_phone_book(char _name[10], char _last_name[10], char _number[10])
{
	contact[index].set_name(_name);
	contact[index].set_lastname(_last_name);
	contact[index].set_number(_number);
	index++;
}

int PhoneBook::get_index()
{
	return (index);
}

void PhoneBook::print_contact(int index)
{
	std::cout<<contact[index].get_name()
		<<std::endl<<contact[index].get_last_name()
		<<std::endl<<contact[index].get_number()<<std::endl;

}

PhoneBook::~PhoneBook()
{
	
}
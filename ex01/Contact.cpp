/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:18:39 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/14 20:54:47 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string.h>

Contact::Contact()
{
	strcpy(name, " ");
	strcpy(last_name, " ");
	strcpy(number, " ");
}

Contact::Contact(char _name[10], char _last_name[10], char _number[10])
{
	strcpy(name,_name);
	strcpy(last_name, _last_name);
	strcpy(number, _number);
}

void Contact::set_name(char _name[10])
{
	strcpy(name,_name);
}

void Contact::set_lastname(char _last_name[10])
{
	strcpy(last_name,_last_name);
}

void Contact::set_number(char _number[10])
{
	strcpy(number,_number);
}

char* Contact:: get_name()
{
	return (name);
}

char* Contact:: get_last_name()
{
	return (last_name);
}

char* Contact:: get_number()
{
	return (number);
}

Contact::~Contact()
{
	
}
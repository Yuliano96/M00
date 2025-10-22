/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:18:39 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/22 19:38:00 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string.h>

Contact::Contact()
{
	name = "";
	last_name = "";
	number = "";
}


void Contact::set_name(const std::string &_name)
{
	name = _name;
}

void Contact::set_lastname(const std::string &_last_name)
{
	last_name = _last_name;
}

void Contact::set_number(const std::string &_number)
{
	number = _number;
}

std::string Contact:: get_name() const
{
	return (name);
}

std::string Contact:: get_last_name() const
{
	return (last_name);
}

std::string Contact:: get_number() const
{
	return (number);
}

Contact::~Contact()
{
	
}
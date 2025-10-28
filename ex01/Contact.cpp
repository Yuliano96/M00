/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:18:39 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 06:04:16 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "Contact.hpp"
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
	
}*/

#include "Contact.hpp"

Contact::Contact() 
{
	
}

void Contact::set_first_name(const std::string &v) 
{ 
	first_name = v; 
}

void Contact::set_last_name(const std::string &v) 
{
	last_name = v; 
}

void Contact::set_nickname(const std::string &v) 
{ 
	nickname = v; 
}

void Contact::set_phone_number(const std::string &v)
{ 
	phone_number = v; 
}

void Contact::set_darkest_secret(const std::string &v) 
{ 
	darkest_secret = v;
}

std::string Contact::get_first_name() const 
{ 
	return first_name; 
}

std::string Contact::get_last_name() const 
{ 
	return last_name; 
}

std::string Contact::get_nickname() const 
{ 
	return nickname; 
}

std::string Contact::get_phone_number() const 
{ 
	return phone_number; 
}
std::string Contact::get_darkest_secret() const { return darkest_secret; }

bool Contact::is_empty() const {
    return first_name.empty() && last_name.empty() && nickname.empty()
        && phone_number.empty() && darkest_secret.empty();
}

Contact::~Contact() {}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:36:25 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/24 06:54:52 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
#define PoneBook_H

#include "Contact.hpp"
#include <cstring>
# define Max_contact 3

class PhoneBook
{
	private:
		Contact contact[Max_contact];
		int		index;
	public:
		PhoneBook();
		void add_phone_book(const std::string &_name, const std::string &last_name, \
			const std::string &_number);
		int get_index();
		void print_contact(int index);
		~PhoneBook();
	
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:36:25 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/14 20:47:35 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
#define PoneBook_H

#include "Contact.hpp"
#include <cstring>
# define Max_contact 8

class PhoneBook
{
	private:
		Contact contact[Max_contact];
		int		index;
	public:
		PhoneBook();
		void add_phone_book(char _name[10], char _last_name[10], char _number[10]);
		int get_index();
		void print_contact(int index);
		~PhoneBook();
	
};

#endif
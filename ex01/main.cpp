/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:58:16 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/14 20:58:05 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	char name[] = "yuliano";
	char last_name[] = "pacileo";
	char number[] = "678767602";
	phonebook.add_phone_book(name,last_name, number);
	std::cout<<phonebook.get_index()<<std::endl;
	phonebook.print_contact(0);
	
	return (0);
}
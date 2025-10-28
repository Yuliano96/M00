/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:36:25 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 06:08:11 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*#ifndef PhoneBook_H
#define PhoneBook_H

# define Max_contact 8
#include "Contact.hpp"
#include <cstring>

class PhoneBook
{
	private:
		Contact contact[Max_contact];
		int		index;
		int		size;
	public:
		PhoneBook();
		void add_phone_book(const std::string &_name, const std::string &last_name, \
			const std::string &_number);
		int get_index();
		int get_size();
		void print_contact(int index);
		~PhoneBook();
	
};

#endif*/

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
# define MAX_contacts 8

class PhoneBook 
{
	private:
    	Contact contacts[MAX_contacts];
    	int size;        // número actual de contactos guardados (0..8)
    	int next_index;  // índice circular para la siguiente inserción (0..7)

	public:
    	PhoneBook();
    	void add_contact(const Contact &c);  // inserta/reemplaza de forma circular
    	int  get_size() const;

    	// SEARCH
    	void print_table() const;            // imprime tabla (4 columnas)
    	void print_contact(int index) const; // detalle de un contacto [0..size-1]

    	// Flujo de búsqueda completo: muestra tabla y pide índice válido
    	void search_contact() const;
		~PhoneBook();
};

#endif

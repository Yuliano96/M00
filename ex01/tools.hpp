/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:47:44 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/28 07:05:02 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*# ifndef TOOLS_H
# define TOOLS_H

#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

void	add_contact(std::string &name, std::string &last_name, std::string &number);
int		str_isdigit(std::string &str);
int		str_isalpha(std::string &str);
void	search_contact(PhoneBook &phonebook);

#endif
*/

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "Contact.hpp"
#include <string>

// Pide una línea no vacía; devuelve "" si EOF.
std::string prompt_non_empty(const std::string &label);

// Construye un contacto interactivo (todos los campos no vacíos).
// Si el usuario hace EOF en cualquier momento, devuelve un contacto "vacío".
Contact build_contact_interactively();

// Lee un índice entero dentro de [min_val, max_val]. Devuelve false en EOF.
bool read_index_in_range(const std::string &label, int min_val, int max_val, int &out_idx);

bool number_of_digits(const std::string &s);
bool is_all_digits_or_sign(const std::string &s);
bool str_isalpha(std::string &str);
// (Opcional) Validación simple para teléfono: solo '+', '-' y dígitos.
bool is_valid_phone(const std::string &s);


#endif

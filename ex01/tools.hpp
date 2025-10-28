/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:47:44 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/28 20:34:47 by yuliano          ###   ########.fr       */
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


std::string prompt_non_empty(const std::string &label);
std::string normalize_spanish_basic(const std::string &s);
Contact build_contact_interactively();
bool read_index_in_range(const std::string &label, int min_val, int max_val, int &out_idx);
bool number_of_digits(const std::string &s);
bool str_isalpha(std::string &str);

#endif

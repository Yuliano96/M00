/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:47:44 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/26 15:40:50 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TOOLS_H
# define TOOLS_H

#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

void	add_contact(std::string &name, std::string &last_name, std::string &number);
int		str_isdigit(std::string &str);
int		str_isalpha(std::string &str);
void	search_contact(PhoneBook &phonebook);

#endif
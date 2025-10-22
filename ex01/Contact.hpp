/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:04:12 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/22 20:07:38 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_H
# define Contact_H

#include <string>

class Contact
{
	private:
		std::string name;
		std::string last_name;
		std::string number;
	public:
		Contact();
		void	set_name(const std::string & _name);
		void	set_lastname(const std::string & _last_name);
		void	set_number(const std::string & _number);

		std::string	get_name() const;
		std::string	get_last_name() const;
		std::string	get_number() const;
		~Contact();
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:04:12 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/14 18:17:55 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_H
# define Contact_H

class Contact
{
	private:
		char name[10];
		char last_name[10];
		char number[10];
	public:
		Contact();
		Contact(char _name[10], char _last_name[10], char _number[10]);
		void	set_name(char _name[10]);
		void	set_lastname(char _last_name[10]);
		void	set_number(char _number[10]);
		char	*get_name();
		char	*get_last_name();
		char	*get_number();
		~Contact();
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:04:12 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/28 20:29:23 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
	private:
    	std::string first_name;
    	std::string last_name;
    	std::string nickname;
    	std::string phone_number;
    	std::string darkest_secret;

	public:
    	Contact();
		
    	// Setters
    	void set_first_name(const std::string &v);
    	void set_last_name(const std::string &v);
   		void set_nickname(const std::string &v);
    	void set_phone_number(const std::string &v);
   		void set_darkest_secret(const std::string &v);

   		// Getters
    	std::string get_first_name() const;
    	std::string get_last_name() const;
    	std::string get_nickname() const;
    	std::string get_phone_number() const;
    	std::string get_darkest_secret() const;

    	// Utilidad
    	bool is_empty() const;
		~Contact();

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:06:03 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/12 19:38:13 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class MegaPhone
{
	private:
		std::string str;
	public:
		MegaPhone(const std::string &s);
		std::string get_mega_phone();
		~MegaPhone();
};

MegaPhone::MegaPhone(const std::string &s) : str(s) {}
std::string MegaPhone::get_mega_phone()
{
	return (str);
}

MegaPhone::~MegaPhone() {}

int main(int argc, char *argv[])
{
	(void)argc;
	MegaPhone p(argv[1]);
	
	std::string p1= p.get_mega_phone();
	std::cout<<p1<<std::endl;
	p1[0] = 'a';
	std::cout<<p1<<std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:06:03 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/13 00:14:35 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
class Megaphone
{
	private:
		const char *str;
	public:
		Megaphone(const char *s);
		const char  *get_mega_phone();
		~Megaphone();
};

Megaphone::Megaphone(const char *s) : str(s) {}

const char *Megaphone:: Megaphone::get_mega_phone()
{
	return (str);
}

Megaphone::~Megaphone() {}

int main(int argc, char *argv[])
{
	(void)argc;
	Megaphone p(argv[1]);
	
	char *p1 = (char *) p.get_mega_phone();
	std::cout<<p1<<std::endl;
	
	return (0);
}
*/


class Megaphone
{
	private:
		std::string str;
	public:
		Megaphone();
		void set_mega_phone(const std::string _str);
		std:: string get_mega_phone();
		~Megaphone();
};

Megaphone::Megaphone()
{
	str = "";
}

std::string Megaphone:: Megaphone::get_mega_phone()
{
	return (str);
}

void Megaphone::set_mega_phone(const std::string _str)
{
	str = _str;
}

Megaphone::~Megaphone() {}

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1)
		std::cout<<"Error"<<std::endl;
	else
	{
		Megaphone *megaphone = new Megaphone[argc];
		i = 1;
		while(i < argc)
		{
			megaphone[i].set_mega_phone(argv[i]);
			i++;
		}
		i = 1;
		while(i < argc)
		{
			std::cout<<megaphone[i].get_mega_phone()<<std::endl;
			i++;
		}
		delete [] megaphone;
	}
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:06:03 by yuliano           #+#    #+#             */
/*   Updated: 2025/10/13 21:25:41 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>


class Megaphone
{
	private:
		std::string str;
	public:
		Megaphone();
		void set_mega_phone(const std::string &xstr);
		void convert_to_uppercase();
		std:: string get_mega_phone() const;
		~Megaphone();
};

Megaphone::Megaphone()
{
	str = "";
}

std::string Megaphone::get_mega_phone() const
{
	return (str);
}

void Megaphone::convert_to_uppercase()
{
	for(size_t i = 0; i < str.size(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}

void Megaphone::set_mega_phone(const std::string &_str)
{
	str = _str;
}

Megaphone::~Megaphone() 
{
}


int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		Megaphone *megaphone = new Megaphone[argc - 1];
        
        // Llenar los objetos
        for (int i = 1; i < argc; i++)
        {
            megaphone[i - 1].set_mega_phone(argv[i]);
        }
        
        // Convertir y mostrar
        for (int i = 0; i < (argc - 1); i++)
        {
            megaphone[i].convert_to_uppercase();
            std::cout << megaphone[i].get_mega_phone() <<" ";
        }
        std::cout<<std::endl;
        delete[] megaphone;
	}
	
	return (0);
}

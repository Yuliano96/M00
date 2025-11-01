/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:06:03 by yuliano           #+#    #+#             */
/*   Updated: 2025/11/01 11:23:46 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:09:00 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/11 23:32:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ejemplo de funcionamiento:
// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *

#include <iostream>
#include <cctype>

std::string trim(const std::string& str) 
{
	size_t first;
	size_t last;

    first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) return "";

    last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

int	main(int argc, char **argv) 
{
	std::string str;
	unsigned char uc;

	if (argc == 1) 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++) 
	{
		str = argv[i];
		str = trim(str);
		for (size_t j = 0; j < str.size(); j++) 
		{
			uc = static_cast<unsigned char>(str[j]);
			std::cout << static_cast<char>(std::toupper(uc));

		}
		std::cout << " ";
	}
	std::cout << '\n';
	return (0);
}

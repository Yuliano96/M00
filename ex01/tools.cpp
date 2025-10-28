/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:44:59 by ypacileo          #+#    #+#             */
/*   Updated: 2025/10/28 20:32:20 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tools.hpp"
#include <iostream>

bool number_of_digits(const std::string &s)
{

    if (s.size() == 9)
    {
        for (size_t i = 0; i < s.size(); ++i)
            if (s[i] < '0' || s[i] > '9')
                return false;
        return true;
    }

    else if (s.size() == 12 && s.substr(0, 3) == "+34")
    {
        for (size_t i = 3; i < s.size(); ++i)
            if (s[i] < '0' || s[i] > '9')
                return false;
        return true;
    }

    return false;
}


std::string prompt_non_empty(const std::string &label) 
{
    std::string s;
    while (true) 
	{
        std::cout << label;
        if (!std::getline(std::cin, s)) 
		{
            std::cout << std::endl; // EOF o error
            return "";
        }
        if (!s.empty())
			return s;
        std::cout << "The field cannot be empty. Please try again." << std::endl;
    }
}


// Mapea secuencias UTF-8 comunes en español a ASCII.
// Maneja: áéíóúüñ (y mayúsculas).
// Estrategia: recorre bytes; si detecta 0xC3, mira el siguiente y sustituye.
std::string normalize_spanish_basic(const std::string &s) 
{
    std::string out;
    for (std::size_t i = 0; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);

        // UTF-8 dos bytes que empiezan por 0xC3
        if (c == 0xC3 && i + 1 < s.size()) {
            unsigned char d = static_cast<unsigned char>(s[i + 1]);

            // minúsculas
            if (d == 0xA1) { out += 'a'; i++; continue; } // á
            if (d == 0xA9) { out += 'e'; i++; continue; } // é
            if (d == 0xAD) { out += 'i'; i++; continue; } // í
            if (d == 0xB3) { out += 'o'; i++; continue; } // ó
            if (d == 0xBA) { out += 'u'; i++; continue; } // ú
            if (d == 0xBC) { out += 'u'; i++; continue; } // ü
            if (d == 0xB1) { out += 'n'; i++; continue; } // ñ

            // mayúsculas
            if (d == 0x81) { out += 'A'; i++; continue; } // Á
            if (d == 0x89) { out += 'E'; i++; continue; } // É
            if (d == 0x8D) { out += 'I'; i++; continue; } // Í
            if (d == 0x93) { out += 'O'; i++; continue; } // Ó
            if (d == 0x9A) { out += 'U'; i++; continue; } // Ú
            if (d == 0x9C) { out += 'U'; i++; continue; } // Ü
            if (d == 0x91) { out += 'N'; i++; continue; } // Ñ

            // Si era 0xC3 pero no lo mapeamos, descartamos ambos o
            // solo copiamos el segundo? Mejor descartarlos para no “romper” ancho.
            // Avanzamos i para saltar el segundo byte.
            i++;
            continue;
        }

        // ASCII normal, lo dejamos tal cual
        if (c < 128) {
            out += static_cast<char>(c);
        }
        // Otros bytes no-ASCII (multibyte de otro rango): los descartamos.
    }
    return out;
}


bool str_isalpha(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]) && str[i] != ' ')
			return (false);
	}
	return (true);
}

Contact build_contact_interactively() 
{
    Contact c;
    std::string v;

	while(true)
	{
		v = prompt_non_empty("Name: ");
		if (v.empty())
			return Contact();
		v = normalize_spanish_basic(v);
		if (str_isalpha(v))
				break;
        std::cout << "invalid." << std::endl;
	}
    c.set_first_name(v);
	
	while(true)
	{
		v = prompt_non_empty("Surnames: ");
		if (v.empty())
			return Contact();
		v = normalize_spanish_basic(v);
		if (str_isalpha(v))
			break;
        std::cout << "invalid." << std::endl;
	}
	
    c.set_last_name(v);
	while(true)
	{
		v = prompt_non_empty("Nickname: ");
		if (v.empty())
			return Contact();
		v = normalize_spanish_basic(v);
		if (str_isalpha(v))
			break;
        std::cout << "Invalid nickname. Use only letters A-Z." << std::endl;
	}
    c.set_nickname(v);

    while (true) 
	{
        v = prompt_non_empty("Phone number: ");
        if (v.empty())
			return Contact();
        
        if (number_of_digits(v)) break;
        std::cout << "Invalid phone number." << std::endl;
    }
    c.set_phone_number(v);

    v = prompt_non_empty("Darkest secret:");
	v = normalize_spanish_basic(v);
    if (v.empty()) 
		return Contact();
    c.set_darkest_secret(v);

    return c;
}

bool read_index_in_range(const std::string &label, int min_val, int max_val, int &out_idx) 
{
    std::string line;
	
    while (true) 
	{
        std::cout << label;
        if (!std::getline(std::cin, line)) 
		{
            std::cout << std::endl; // EOF
            return false;
        }
        if (line.empty()) {
            std::cout << "Empty index." << std::endl;
            continue;
        }
		
        bool ok = true;
        int sign = 1;
        std::size_t i = 0;
        long val = 0;

        if (line[0] == '+' || line[0] == '-') { sign = (line[0] == '-') ? -1 : 1; i = 1; }
        if (i >= line.size()) ok = false;

        for (; ok && i < line.size(); ++i) 
		{
            if (line[i] < '0' || line[i] > '9') 
			{ 
				ok = false; 
				break; 
			}
            val = val * 10 + (line[i] - '0');
            if (val > 1000000) break; // evitar overflow tonto
        }
        if (!ok) {
            std::cout << "Invalid entry." << std::endl;
            continue;
        }
        val *= sign;
        if (val < min_val || val > max_val) {
            std::cout << "Index out of range (" << min_val << "-" << max_val << ")." << std::endl;
            continue;
        }
        out_idx = static_cast<int>(val);
        return true;
    }
}

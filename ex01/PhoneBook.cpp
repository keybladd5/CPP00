/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:44:19 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/13 20:44:21 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	get_justchars(std::string field)
{
	std::string buff;

	if (field.length() >= 10)
	{
		buff = field.substr(0, 10);
		buff.replace(9, 1, ".");
	}
	else
		buff = field;
	return (buff);
} 

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
	return;
} 
PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destructor called" << std::endl;
    return;
}

//Subject -> A saved contact can’t have empty fields.
void	PhoneBook::add_command(int index)
{
	_contact[index].set_data();
}

void	PhoneBook::exit_command()
{
	std::cout << "Sayonara :$" << std::endl;
}

void	PhoneBook::show_all(int total)
{

	for (int i = 0; i < total; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i;
		for (int x = 0; x < 3; x++)
			std::cout << "|" << std::right << std::setw(10) << get_justchars(_contact[i].get_field(x));
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::search_command(int target, int total)
{
	PhoneBook::show_all(total);
	target = std::getchar();
	if (!std::isdigit(target))
	{
		std::cout << "Only 0 - 7 index target allowed!" << std::endl;
		return;
	}
	std::cout << "|" << std::right << std::setw(10) << target;
	for (int x = 0; x < 5; x++)
		std::cout << "|" << std::right << std::setw(10) << get_justchars(_contact[target].get_field(x));
	std::cout << "|" << std::endl;
}

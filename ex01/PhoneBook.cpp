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
	PhoneBook::_index = 0;
	return;
} 
PhoneBook::~PhoneBook(void)
{
    return;
}

void	PhoneBook::add_command()
{
	if (_index > 7)
		_index = 0;
	_contacts[_index].set_data();
	_index++;
}

int		PhoneBook::exit_command()
{
	std::cout << "Sayonara :$" << std::endl;
	return (0);
}

int		PhoneBook::get_contacts(void)
{
	int i = 0;
	while (_contacts[i].validation())
		i++;
	return (i - 1);
}

void	PhoneBook::show_all(int total)
{
	std::cout << "|" << std::right << std::setw(10) << "INDEX";
	std::cout << "|" << std::right << std::setw(10) << "FIRSTNAME";
	std::cout << "|" << std::right << std::setw(10) << "LASTNAME";
	std::cout << "|" << std::right << std::setw(10) \
	<< "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < total; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i;
		for (int x = 0; x < 3; x++)
		{
			std::cout << " x -> " << x << " total -> " << total << "i ->" << i << std::endl;
			std::cout << "|" << std::right << std::setw(10) << get_justchars(_contacts[i].get_field(x));
		}
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::print_all(int nb_target)
{
	for (int x = 0; x < 5; x++)
	{
		//std::cout << " x -> " << x << " nb_target -> " << nb_target << std::endl;
		if (x == FNAME)
			std::cout << "First name: ";
		else if (x == LNAME)
			std::cout << "Last name: ";
		else if (x == NNAME)
			std::cout << "Nick name: ";
		else if (x == PNUMBER)
			std::cout << "Phone number: ";
		else if (x == DSECRET)
			std::cout << "Darkest secret: ";
		std::cout << _contacts[nb_target].get_field(x) << std::endl;
	}
}

void	PhoneBook::search_command(int total)
{
	std::string target;
	int nb_target = 0;
	show_all(total);
	std::cout << "Index: ";
	while(!std::getline(std::cin, target) || target.length() > 1 || _contacts[0].isdigit_str(target))
	{
		std::cout << "Only 0 - 7 index target allowed!" << std::endl;
		if (std::cin.eof())
			return;
		std::cout << "Index: ";
	}
	nb_target = target[0] - '0';
	if (nb_target > total || (nb_target >= total && nb_target >= 8))
	{
		if (nb_target == 8 || nb_target == 9)
			std::cout << "Only 0 - 7 index target allowed!" << std::endl;
		else
			std::cout << "Empty contact" << std::endl;
		return;
	}
	print_all(nb_target);
}

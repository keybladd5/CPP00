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
	//std::cout << "PhoneBook constructor called" << std::endl;
	PhoneBook::_index = 0;
	return;
} 
PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook destructor called" << std::endl;
    return;
}

//Subject -> A saved contact can’t have empty fields.
void	PhoneBook::add_command()
{
	if (_index > 7)
		_index = 0;
	_contact[_index].set_data();
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
	while (_contact[i].validation())
		i++;
	return (i);
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

void	PhoneBook::search_command(int total)
{
	std::string target;
	int tmp = 0;

	// print("INDEX| FIRST NAME| LAST NAME| NICKNAME")
	show_all(total);
	std::cout << "Index: ";
	while(!std::getline(std::cin, target) || target.length() > 1)
	{
		std::cout << "Only 0 - 7 index target allowed!" << std::endl;
		if (std::cin.eof())
			return;
		std::cout << "Index: ";
	}
	tmp = target[0] - '0';
	if (tmp > total || !(tmp == 0 && get_contacts() == 1))
	{
		std::cout << "Empty contact" << std::endl;
		return;
	}
	_index = tmp;
	for (int x = 0; x < 5; x++)
	{
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
		std::cout << _contact[_index].get_field(x) << std::endl; //contactSSSSSSSSSSSSSSSS
	}
}

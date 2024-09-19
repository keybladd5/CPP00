/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:44:33 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/13 20:44:35 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	return;
}
Contact::~Contact(void)
{
    std::cout << "Contact destructor called" << std::endl;
    return;
}

std::string Contact::get_field(int type) const
{
	
	if (type == FNAME)
		return (Contact::_firstname);
	else if (type == LNAME)
		return (Contact::_lastname);
	else if (type == NNAME)
		return (Contact::_nickname);
	else if (type == PNUMBER)
		return (Contact::_phone_number);
	else if (type == DSECRET)
		return (Contact::_darkest_secret);
	else
		return ("");
}

int	Contact::set_field(int type, std::string field)
{
	if (!field.length())
		return (1);
	if (type == FNAME)
		Contact::_firstname = field;
	else if (type == LNAME)
		Contact::_lastname = field;
	else if (type == NNAME)
		Contact::_nickname = field;
	else if (type == PNUMBER)
	{
		for (int i = 0; i < (int)field.length(); i++)
		{
			if (field[i] < '0' || field[0] > '9')
				return (2);
		}
		Contact::_phone_number = field;
	}
	else if (type == DSECRET)
		Contact::_darkest_secret = field;
	return (0);
}


void	Contact::set_data(void)
{
	int err = 0;
	std::string buff;
	for (int i = 0; i < 5; i++)
	{
		if (err)
		{
			i--;
			err--;
		}
		if (i == FNAME)
			std::cout << "First name: ";
		else if (i == LNAME)
			std::cout << "Last name: ";
		else if (i == NNAME)
			std::cout << "Nick name: ";
		else if (i == PNUMBER)
			std::cout << "Phone number: ";
		else if (i == DSECRET)
			std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, buff) || Contact::set_field(i, buff))
		{
			err = 1;
			if (!buff.length())
			{
				std::cout << "Can't store empty field!" << std::endl;
				if (std::cin.eof())
					return;
			}
			else if (i == PNUMBER && buff.length())
				std::cout << "Invalid Phone number!" << std::endl;
		}

	}
}

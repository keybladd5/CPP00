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
	_firstname = "";
	_lastname = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
	return;
}
Contact::~Contact(void)
{
    return;
}
int	Contact::isdigit_str(std::string str)
{
	if (!(int)str.length())
		return (1);
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}
std::string Contact::get_field(int type) const
{
	if (type == FNAME)
		return (_firstname);
	else if (type == LNAME)
		return (_lastname);
	else if (type == NNAME)
		return (_nickname);
	else if (type == PNUMBER)
		return (_phone_number);
	else if (type == DSECRET)
		return (_darkest_secret);
	else
		return ("");
}

int	Contact::set_field(int type, std::string field)
{
	if (!field.length())
		return (1);
	if (type == FNAME)
		_firstname = field;
	else if (type == LNAME)
		_lastname = field;
	else if (type == NNAME)
		_nickname = field;
	else if (type == PNUMBER)
	{
		if (isdigit_str(field))
			return (1);
		_phone_number = field;
	}
	else if (type == DSECRET)
		_darkest_secret = field;
	return (0);
}

static int	handler_error_data(std::string buff, int *err, int i)
{
	*err = 1;
	if (!buff.length())
	{
		std::cout << "Can't store empty field!" << std::endl;
		if (std::cin.eof())
			return (1);
	}
	else if (i == PNUMBER && buff.length())
		std::cout << "Invalid Phone number!" << std::endl;
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
		if (!std::getline(std::cin, buff) || set_field(i, buff))
		{
			if (handler_error_data(buff, &err, i))
				return;
		}
	}
}

int		Contact::validation()
{
	if (_firstname.length() > 0 && _lastname.length() > 0 \
	&& _nickname.length() > 0 && _phone_number.length() > 0 \
	&& _darkest_secret.length() > 0)
		return (1);
	return (0);
}

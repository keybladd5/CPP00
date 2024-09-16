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

std::string Contact::get_field(std::string field) const
{
	if (field == "firstname")
		return (Contact::_firstname);
	else if (field == "lastname")
		return (Contact::_lastname);
	else if (field == "nickname")
		return (Contact::_nickname);
	else if (field == "phone_number")
		return (Contact::_phone_number);
	else if (field == "darkest_secret")
		return (Contact::_darkest_secret);
	else
		return ("");
}

void	Contact::set_field(int type, std::string field)
{
	if (type == FNAME)
		Contact::_firstname = field;
	else if (type == LNAME)
		Contact::_lastname = field;
	else if (type == NNAME)
		Contact::_nickname = field;
	else if (type == PNUMBER)
		Contact::_phone_number = field;
	else if (type == DSECRET)
		Contact::_darkest_secret = field;
}

void	Contact::set_data(void)
{
	std::string buff;
	for (int i = 0; i < 5; i++)
	{
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
		std::cin >> buff;
		Contact::set_field(i, buff);
		//buff.erase();
	}
}

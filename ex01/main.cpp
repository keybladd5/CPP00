/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:15:53 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/16 19:15:55 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	main_phone;
	std::string	buff = "";
	int total = 0;
	std::cout << "Welcome to ur amazing PhoneBook!" << std::endl;
	while (1)
	{
		std::cout <<  "Use ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, buff))
		{
			if (std::cin.eof())
				return(1);
		}
		else if (buff == "ADD")
			main_phone.add_command();
		else if (buff == "SEARCH")
		{
			total = main_phone.get_contacts();
			main_phone.search_command(total);
		}
		else if (buff == "EXIT")
			return (main_phone.exit_command());
		else
			std::cout << "Only ADD/ SEARCH/ EXIT allowed" << std::endl;
	}
	return (0); 
}

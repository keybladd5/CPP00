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
	PhoneBook telepol;
	
	telepol.add_command(0);
	telepol.add_command(1);
	telepol.add_command(2);
	telepol.add_command(3);
	telepol.add_command(4);
	telepol.show_all(5);
	return (0); 
}

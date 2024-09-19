/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:42:28 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/13 20:42:31 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include "Contact.hpp"


class PhoneBook
{
	private:
			Contact _contact[8];
	public:
			PhoneBook(void);
			~PhoneBook(void);
			void	add_command(int index);
			void	show_all(int total);
			void	search_command(int target, int total);
			void	exit_command(void);
};

#endif
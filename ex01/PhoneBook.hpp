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
			int _index;
	public:
			PhoneBook(void);
			~PhoneBook(void);
			void	add_command(void);
			int		get_contacts(void);
			void	show_all(int total);
			void	search_command(int total);
			int		exit_command(void);
};

#endif

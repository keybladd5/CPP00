/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:42:48 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/13 20:42:49 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

# define FNAME		0
# define LNAME		1
# define NNAME		2
# define PNUMBER	3
# define DSECRET	4

class Contact
{
	private:
			std::string		_firstname;
			std::string		_lastname;
			std::string		_nickname;
			std::string		_phone_number;
			std::string		_darkest_secret;
	public:
			Contact(void);
			~Contact(void);
			std::string 	get_field(int type) const;
			int 			set_field(int type, std::string field);
			void			set_data(void);
			int				validation(void);

};

#endif

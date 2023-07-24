/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:06:56 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>

class PhoneBook{
	public:
		PhoneBook(void);
		virtual ~PhoneBook(void);
		void	addContact();
		void	searchContact();

	private:
		PhoneBook(PhoneBook const & src);
		PhoneBook & operator=(PhoneBook const & rhs);
		Contact	_contacts[8];
		int		_contactsLen;
};

#endif

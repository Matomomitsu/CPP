/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:18:36 by mtomomit          #+#    #+#             */
/*   Updated: 2023/04/24 16:44:09 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact{
	public:
		Contact(void);
		virtual ~Contact(void);
		Contact & operator=(Contact const & rhs);
		Contact(Contact const & src);
		void		setLastName(std::string lastName);
		std::string	getLastName(void) const;
		void		setFirstName(std::string firstName);
		std::string	getFirstName(void) const;
		void		setNickname(std::string nickname);
		std::string	getNickname(void) const;
		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber(void) const;
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getDarkestSecret(void) const;
	private:
		std::string	_lastName;
		std::string	_firstName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif

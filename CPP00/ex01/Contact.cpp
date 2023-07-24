/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:08:05 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::~Contact(void)
{
	return ;
}

Contact::Contact()
{
	return ;
}

Contact::Contact(Contact const & src) {

	*this = src;
	return;
}

Contact &	Contact::operator=(Contact const & rhs)
{
	if (this != &rhs){
		this->_firstName = rhs.getFirstName();
		this->_darkestSecret = rhs.getDarkestSecret();
		this->_lastName = rhs.getLastName();
		this->_nickname = rhs.getNickname();
		this->_phoneNumber = rhs.getPhoneNumber();
	}
	return (*this);
}

void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

void	Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

void	Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

std::string	Contact::getNickname() const
{
	return (_nickname);
}

bool is_digits(std::string& str)
{
	int		i;

	i = 0;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (false);
		i++;
	}
	return (true);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	std::string	input;

	while (!is_digits(phoneNumber))
	{
		std::cout << "Invalid phone number put another" << std::endl;
		std::getline(std::cin, input);
		phoneNumber = input;
		if (input == "\0" || std::cin.eof())
			return ;
	}
	_phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

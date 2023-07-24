/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:08:02 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void)
{
	return ;
}

PhoneBook::PhoneBook() : _contactsLen(0)
{
	return ;
}

PhoneBook::PhoneBook(PhoneBook const & src) {

	*this = src;
	return;
}

PhoneBook &	PhoneBook::operator=(PhoneBook const & rhs)
{
	if (this != &rhs){
	}
	return (*this);
}

void	getNewContact(Contact	*newContact)
{
	std::string	input;

	std::cout << "Insert first name: " << std::endl;
	std::getline(std::cin, input);
	if (input == "\0" || std::cin.eof())
		return ;
	else
		newContact->setFirstName(input);
	std::cout << "Insert last name: " << std::endl;
	std::getline(std::cin, input);
	if (input == "\0" || std::cin.eof())
		return ;
	else
		newContact->setLastName(input);
	std::cout << "Insert nickname: " << std::endl;
	std::getline(std::cin, input);
	if (input == "\0" || std::cin.eof())
		return ;
	else
		newContact->setNickname(input);
	std::cout << "Insert phone number: " << std::endl;
	std::getline(std::cin, input);
	if (input == "\0" || std::cin.eof())
		return ;
	else
		newContact->setPhoneNumber(input);
	std::cout << "Insert darkest secret " << std::endl;
	std::getline(std::cin, input);
	if (input == "\0" || std::cin.eof())
		return ;
	else
		newContact->setDarkestSecret(input);
}

void	PhoneBook::addContact()
{
	Contact	newContact;

	getNewContact(&newContact);
	if (newContact.getDarkestSecret() == "\0" || newContact.getFirstName() == "\0" || \
		newContact.getLastName() == "\0" || newContact.getNickname() == "\0" || newContact.getPhoneNumber() == "\0")
	{
		std::cout << "One of the fields was empty. New contact wasn't created" << std::endl;
		return ;
	}
	if (this->_contactsLen < 8)
	{
		this->_contacts[7 - _contactsLen].setFirstName(newContact.getFirstName());
		this->_contacts[7 - _contactsLen].setLastName(newContact.getLastName());
		this->_contacts[7 - _contactsLen].setNickname(newContact.getNickname());
		this->_contacts[7 - _contactsLen].setPhoneNumber(newContact.getPhoneNumber());
		this->_contacts[7 - _contactsLen].setDarkestSecret(newContact.getDarkestSecret());
		this->_contactsLen++;
	}
	else
	{
		for (int i = 6; i >= 0; i--)
		{
			this->_contacts[i + 1].setFirstName(this->_contacts[i].getFirstName());
			this->_contacts[i + 1].setLastName(this->_contacts[i].getLastName());
			this->_contacts[i + 1].setNickname(this->_contacts[i].getNickname());
			this->_contacts[i + 1].setPhoneNumber(this->_contacts[i].getPhoneNumber());
			this->_contacts[i + 1].setDarkestSecret(this->_contacts[i].getDarkestSecret());
		}
		this->_contacts[0].setFirstName(newContact.getFirstName());
		this->_contacts[0].setLastName(newContact.getLastName());
		this->_contacts[0].setNickname(newContact.getNickname());
		this->_contacts[0].setPhoneNumber(newContact.getPhoneNumber());
		this->_contacts[0].setDarkestSecret(newContact.getDarkestSecret());
	}
	return ;
}

void	printData(std::string data)
{
	int	o;
	int	dataLen;

	o = 0;
	dataLen = data.length();
	if (data.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << data[i];
		std::cout << "." << "|";
	}
	else
	{
		while (o + dataLen < 10)
		{
			std::cout << " ";
			o++;
		}
		o = 0;
		while (data[o])
		{
			std::cout << data[o];
			o++;
		}
		std::cout << "|";
	}
}

void	PhoneBook::searchContact()
{
	std::string	data;
	int			index;

	index = 0;
	std::cout << "********************************************" << std::endl;
	std::cout << "|    index|first name| last name|  nickname|" << std::endl;
	while (index < this->_contactsLen)
	{
		std::cout << "|        " << index << "|";
		data = this->_contacts[7 - index].getFirstName();
		printData(data);
		data = this->_contacts[7 - index].getLastName();
		printData(data);
		data = this->_contacts[7 - index].getNickname();
		printData(data);
		index++;
		std::cout << std::endl;
	}
	std::cout << "********************************************" << std::endl;
	return ;
}

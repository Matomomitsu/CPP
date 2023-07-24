/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:41:13 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;

	std::getline(std::cin, input);
	while (input != "EXIT\0" && !std::cin.eof())
	{
		if (input == "ADD\0")
			phonebook.addContact();
		else
		{
			if (input == "SEARCH")
				phonebook.searchContact();
			else
				std::cout << "Invalid command please try another" << std::endl;
		}
		std::getline(std::cin, input);
	}
	return (0);
}

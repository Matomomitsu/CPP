/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:48:48 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 02:24:47 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		std::cout << "BOB: \n" << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << "Setting club as Bob weapon" << std::endl;
		HumanA bob("Bob", club);
		bob.attack();
		std::cout << "Setting other type of club as Bob weapon" << std::endl;
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "JIM: \n" << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << "Initializing Jim without weapon" << std::endl;
		HumanB jim("Jim");
		jim.attack();
		std::cout << "Setting club as Jim weapon" << std::endl;
		jim.setWeapon(club);
		jim.attack();
	}
	return 0;
}

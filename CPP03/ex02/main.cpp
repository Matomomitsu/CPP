/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:11:47 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/11 14:42:47 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap fragTrap("FRAGTRAP");

	fragTrap.beRepaired(50);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(50);
	fragTrap.attack("ClapTrap");
	fragTrap.takeDamage(150);
	fragTrap.highFivesGuys();
	return (0);
}

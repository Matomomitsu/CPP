/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:11:47 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 04:12:45 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondTrap("DIAMOND");

	diamondTrap.beRepaired(50);
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.takeDamage(50);
	diamondTrap.beRepaired(50);
	diamondTrap.attack("ClapTrap");
	diamondTrap.whoAmI();
	return (0);
}

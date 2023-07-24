/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:45 by mtomomit          #+#    #+#             */
/*   Updated: 2023/07/06 22:21:42 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	ct("CLAPTRAP");
	int			i;

	i = 0;
	ct.attack("SCAVTRAP");
	ct.takeDamage(5);
	ct.beRepaired(5);
	while (i < 10)
	{
		ct.takeDamage(5);
		ct.beRepaired(5);
		i++;
	}
	ct.takeDamage(5);
	return (0);
}

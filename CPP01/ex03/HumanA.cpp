/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:48:43 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name) , _weapon(weapon){
	return ;
}

HumanA::~HumanA(void){
	return ;
}

std::string	HumanA::getName() const{
	return (this->_name);
}

void HumanA::setName(std::string name){
	this->_name = name;
	return ;
}

void	HumanA::attack() const{
	std::cout << getName() << " attacks with their " << this->_weapon.getType() << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:49:19 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB(void){
	return ;
}

std::string	HumanB::getName() const{
	return (this->_name);
}

void HumanB::setName(std::string name){
	this->_name = name;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}

void	HumanB::attack() const{
	if (this->_weapon != NULL)
		std::cout << getName() << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << getName() << " attacks with their hand" << std::endl;
}

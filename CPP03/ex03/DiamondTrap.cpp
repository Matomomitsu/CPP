/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:18:12 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/11 15:05:02 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DiamondTrap_clap_name"), FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap was created (DiamondTrap constructor)" << std::endl;
	this->_name = "DiamondTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << this->_name << " was destructed (DiamondTrap destructor)" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs){
	if(this != &rhs){
		this->ClapTrap::_name = rhs.getName();
		this->_name = rhs._name;
		this->_attackDamage = rhs.getAttackDamage();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		std::cout << this->_name << " was created (DiamondTrap constructor)" << std::endl;
	}
	return(*this);
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(), FragTrap(), ScavTrap(){
	*this = src;
	std::cout << this->_name << " was created (DiamondTrap constructor)" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){
	this->_name = name;
	std::cout << this->_name << " was created (DiamondTrap constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_maxHitPoints = 100;
}

void	DiamondTrap::whoAmI(){
	std::cout << "My ClapTrap name is " << this->getName() << ". And my DiamondTrap name is " << \
		this->_name << std::endl;
}

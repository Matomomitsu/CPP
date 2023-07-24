/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:13:31 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/11 15:00:23 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap"){
	std::cout << "ScavTrap was created (ScavTrap constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

ScavTrap::~ScavTrap(void){
	std::cout << this->_name << " was destructed (ScavTrap destructor)" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
	if(this != &rhs){
		this->_name = rhs.getName();
		this->_attackDamage = rhs.getAttackDamage();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		std::cout << this->_name << " was created (ScavTrap constructor)" << std::endl;
	}
	return(*this);
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(){
	*this = src;
	std::cout << this->_name << " was created (ScavTrap constructor)" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << this->_name << " was created (ScavTrap constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

bool	checkStatus(ScavTrap *scavTrap)
{
	if (scavTrap->getHitPoints() == 0)
	{
		std::cout << scavTrap->getName() << " is dead" << std::endl;
		return (false);
	}
	if (scavTrap->getEnergyPoints() == 0)
	{
		std::cout << scavTrap->getName() << " is tired" << std::endl;
		return (false);
	}
	return (true);
}

void	ScavTrap::attack(const std::string& target)
{
	if (checkStatus(this))
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " \
		<< this->getAttackDamage() << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate(){
	if (this->getHitPoints() != 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " is dead" << std::endl;
	}
}

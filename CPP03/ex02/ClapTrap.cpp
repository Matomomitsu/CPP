/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:11:16 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/11 14:58:44 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10){
	std::cout << "ClapTrap was created (ClapTrap constructor)" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << this->_name << " was destructed (ClapTrap destructor)" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){
	if(this != &rhs){
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		std::cout << this->getName() << " was created (ClapTrap constructor)" << std::endl;
	}
	return(*this);
}

ClapTrap::ClapTrap(ClapTrap const & src){
	*this = src;
	std::cout << this->getName() << " was created (ClapTrap constructor)" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10){
	std::cout << name << " was created (ClapTrap constructor)" << std::endl;
}

std::string	ClapTrap::getName(void) const{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const{
	return (this->_attackDamage);
}

bool	checkStatus(ClapTrap *clapTrap)
{
	if (clapTrap->getHitPoints() == 0)
	{
		std::cout << clapTrap->getName() << " is dead" << std::endl;
		return (false);
	}
	if (clapTrap->getEnergyPoints() == 0)
	{
		std::cout << clapTrap->getName() << " is tired" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target){
	if (checkStatus(this))
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " \
		<< this->getAttackDamage() << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->getHitPoints() == 0)
		std::cout << this->getName() << " is already dead" << std::endl;
	else
	{
		if (amount >= this->getHitPoints())
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << this->getName() << " suffered " << amount << " of damage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (checkStatus(this))
	{
		if (this->_hitPoints == this->_maxHitPoints){
			std::cout << this->getName() << " already is full hp" << std::endl;
			return ;
		}
		if (this->_hitPoints + amount > this->_maxHitPoints)
			this->_hitPoints = this->_maxHitPoints;
		else
			this->_hitPoints += amount;
		std::cout << this->getName() << " repaired himself now has " << this->_hitPoints << "hp" << std::endl;
		this->_energyPoints--;
	}
}

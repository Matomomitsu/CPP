/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:06:39 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/11 15:00:34 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap"){
	std::cout << "FragTrap was created (FragTrap constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHitPoints = 100;
}

FragTrap::~FragTrap(void){
	std::cout << this->_name << " was destructed (FragTrap destructor)" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs){
	if(this != &rhs){
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		std::cout << this->getName() << " was created (FragTrap constructor)" << std::endl;
	}
	return(*this);
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(){
	*this = src;
	std::cout << this->getName() << " was created (FragTrap constructor)" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << this->_name << " was created (FragTrap constructor)" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHitPoints = 100;
}

void	FragTrap::highFivesGuys(void){
	if (this->getHitPoints() != 0)
	{
		std::cout << "Let`s do a high five guys!!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->getName() << " is dead" << std::endl;
	}
}


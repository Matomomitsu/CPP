/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:19:52 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	std::cout << _name << ": Zombie created" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << _name << ": Zombie destroyed" << std::endl;
}

Zombie::Zombie(Zombie const & src) {
	*this = src;
	return;
}

Zombie &	Zombie::operator=(Zombie const & rhs)
{
	if (this != &rhs){
		this->_name = rhs.getName();
	}
	return (*this);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName() const
{
	return (this->_name);
}

void	Zombie::announce(void){
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

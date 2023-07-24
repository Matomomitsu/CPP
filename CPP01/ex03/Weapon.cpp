/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:48:53 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 16:55:50 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){
	return ;
}

Weapon::~Weapon(void){
	return ;
}

Weapon & Weapon::operator=(Weapon const & rhs){
	if (this != &rhs){
		this->_type = rhs.getType();
	}
	return (*this);
}

Weapon::Weapon(Weapon const & src){
	*this = src;
	return ;
}

std::string	const &Weapon::getType() const{
	return (this->_type);
}

void	Weapon::setType(std::string type){
	this->_type = type;
	return ;
}

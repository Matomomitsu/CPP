/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:53 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 19:56:57 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Horse"){
	std::cout << "AAnimal was created (AAnimal constructor)" << std::endl;
}

AAnimal::~AAnimal(void){
	std::cout << this->_type << " was destructed (AAnimal destructor)" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs){
	std::cout << "AAnimal Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

AAnimal::AAnimal(AAnimal const & src){
	std::cout << "AAnimal was created (Animal copy constructor)" << std::endl;
	*this = src;
	return ;
}

std::string	AAnimal::getType() const{
	return (_type);
}

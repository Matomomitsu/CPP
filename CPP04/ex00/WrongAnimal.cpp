/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:13:25 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:06:42 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongHorse"){
	std::cout << "WrongAnimal was created (WrongAnimal constructor)" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << this->_type << " was destructed (WrongAnimal destructor)" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
	std::cout << "WrongAnimal Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	std::cout << "WrongAnimal was created (WrongAnimal copy constructor)" << std::endl;
	*this = src;
	return ;
}

void	WrongAnimal::makeSound() const{
	std::cout << "!!hgieN" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (_type);
}

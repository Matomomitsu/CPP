/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:14:00 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:01:22 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
	_type = "Dog";
	std::cout << "Dog was created (Dog constructor)" << std::endl;
}

Dog::~Dog(void){
	std::cout << this->_type << " was destructed (Dog destructor)" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs){
	std::cout << "Dog Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

Dog::Dog(Dog const & src) : Animal(src){
	std::cout << "Dog was created (Dog copy constructor)" << std::endl;
	*this = src;
	return ;
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof" << std::endl;
}

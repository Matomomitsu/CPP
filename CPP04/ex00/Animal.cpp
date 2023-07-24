/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:53 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:00:25 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Horse"){
	std::cout << "Animal was created (Animal constructor)" << std::endl;
}

Animal::~Animal(void){
	std::cout << this->_type << " was destructed (Animal destructor)" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs){
	std::cout << "Animal Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

Animal::Animal(Animal const & src){
	std::cout << "Animal was created (Animal copy constructor)" << std::endl;
	*this = src;
	return ;
}

void	Animal::makeSound() const{
	std::cout << "Neigh!!" << std::endl;
}

std::string	Animal::getType() const{
	return (_type);
}

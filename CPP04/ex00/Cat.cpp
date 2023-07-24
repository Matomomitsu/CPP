/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:57 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:02:17 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
	_type = "Cat";
	std::cout << "Cat was created (Cat constructor)" << std::endl;
}

Cat::~Cat(void){
	std::cout << this->_type << " was destructed (Cat destructor)" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs){
	std::cout << "Cat Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

Cat::Cat(Cat const & src) : Animal(src){
	std::cout << "Cat was created (Cat copy constructor)" << std::endl;
	*this = src;
	return ;
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

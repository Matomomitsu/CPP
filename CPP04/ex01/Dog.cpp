/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:14:00 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 19:44:25 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
	std::cout << "Dog was created (Dog constructor)" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(void){
	std::cout << this->_type << " was destructed (Dog destructor)" << std::endl;
	delete _brain;
}

Dog & Dog::operator=(Dog const & rhs){
	std::cout << "Dog Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
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

void	Dog::setIdea(int ideaNum, std::string idea){
	if (ideaNum < 0 || ideaNum > 99)
		return ;
	else
		this->_brain->ideas[ideaNum] = idea;
}

std::string	Dog::getIdea(int ideaNum){
	if (ideaNum < 0 || ideaNum > 99)
		return ("");
	else
		return (this->_brain->ideas[ideaNum]);
}

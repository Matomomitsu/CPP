/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:57 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 19:43:45 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
	std::cout << "Cat was created (Cat constructor)" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat(void){
	std::cout << this->_type << " was destructed (Cat destructor)" << std::endl;
	delete _brain;
}

Cat & Cat::operator=(Cat const & rhs){
	std::cout << "Cat Copy assigment operator called" << std::endl;
	if(this != &rhs){
		_brain = new Brain();
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
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

void	Cat::setIdea(int ideaNum, std::string idea){
	if (ideaNum < 0 || ideaNum > 99)
		return ;
	else
		this->_brain->ideas[ideaNum] = idea;
}

std::string	Cat::getIdea(int ideaNum){
	if (ideaNum < 0 || ideaNum > 99)
		return ("");
	else
		return (this->_brain->ideas[ideaNum]);
}

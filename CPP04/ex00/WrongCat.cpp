/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:48 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:07:41 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	_type = "WrongCat";
	std::cout << "WrongCat was created (WrongCat constructor)" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << this->_type << " was destructed (WrongCat destructor)" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs){
	std::cout << "WrongCat Copy assigment operator called" << std::endl;
	if(this != &rhs){
		this->_type = rhs._type;
	}
	return(*this);
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src){
	std::cout << "WrongCat was created (WrongCat copy constructor)" << std::endl;
	*this = src;
	return ;
}

void	WrongCat::makeSound() const{
	std::cout << "woeM woeM" << std::endl;
}

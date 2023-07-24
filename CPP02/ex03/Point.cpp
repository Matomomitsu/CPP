/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:23:36 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)){
}

Point::~Point(void){
}

Point & Point::operator=(Point const & rhs){
	if (this != &rhs){
		(Fixed &)this->_x = rhs.getX();
		(Fixed &)this->_y = rhs.getY();
	}
	return (*this);
}

Point::Point(Point const & src){
	*this = src;
	return;
}

Point::Point(float const xValue, float const yValue) : _x(Fixed(xValue)) , _y(Fixed(yValue)){
}


const Fixed & Point::getX(void) const{
	return (_x);
}

const Fixed & Point::getY(void) const{
	return (_y);
}

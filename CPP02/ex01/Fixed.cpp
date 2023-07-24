/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:15:02 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &rhs){
		this->_rawBits = rhs.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

int	Fixed::getRawBits(void) const{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw){
	this->_rawBits = raw;
}

Fixed::Fixed(int const value)
{
	setRawBits(value << _fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value)
{
	setRawBits(roundf((value * (1 << _fractionalBits))));
	std::cout << "Float constructor called" << std::endl;
}

int		Fixed::toInt() const
{
	return (getRawBits() >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)getRawBits() / (1 << _fractionalBits));
}

std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

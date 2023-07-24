/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:23:32 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0){
}

Fixed::~Fixed(void){
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs){
		this->_rawBits = rhs.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(Fixed const & src){
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
}

Fixed::Fixed(float const value)
{
	setRawBits(roundf((value * (1 << _fractionalBits))));
}

int		Fixed::toInt() const
{
	return (getRawBits() >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((double)getRawBits() / (1 << _fractionalBits));
}

std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const &rhs) const{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed &	Fixed::operator++(void){
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	temp = *this;
	++*this;
	return (temp);
}

Fixed &	Fixed::operator--(void){
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	temp = *this;
	--*this;
	return (temp);
}

Fixed	Fixed::operator-(Fixed const &rhs) const{
	Fixed	temp;

	temp.setRawBits(getRawBits() - rhs.getRawBits());
	return (temp);
}

Fixed	Fixed::operator+(Fixed const &rhs) const{
	Fixed	temp;

	temp.setRawBits(getRawBits() + rhs.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*(Fixed const &rhs) const{
	Fixed	temp;

	temp.setRawBits((getRawBits() * rhs.getRawBits()) >> _fractionalBits);
	return (temp);
}

Fixed	Fixed::operator/(Fixed const &rhs) const{
	Fixed	temp;

	temp.setRawBits((getRawBits() / rhs.getRawBits()) << _fractionalBits);
	return (temp);
}

Fixed &	Fixed::min(Fixed &fixedPoint1, Fixed &fixedPoint2){
	if (fixedPoint1 <= fixedPoint2)
		return (fixedPoint1);
	return (fixedPoint2);
}

Fixed &	Fixed::max(Fixed &fixedPoint1, Fixed &fixedPoint2){
	if (fixedPoint1 >= fixedPoint2)
		return (fixedPoint1);
	return (fixedPoint2);
}

Fixed const &	Fixed::min(Fixed const &fixedPoint1, Fixed const &fixedPoint2){
	if (fixedPoint1 <= fixedPoint2)
		return (fixedPoint1);
	return (fixedPoint2);
}

Fixed const &	Fixed::max(Fixed const &fixedPoint1, Fixed const &fixedPoint2){
	if (fixedPoint1 >= fixedPoint2)
		return (fixedPoint1);
	return (fixedPoint2);
}

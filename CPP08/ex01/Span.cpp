/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:06 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxSize(20){
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize){
}

Span::~Span(void){
}

Span & Span::operator=(Span const & rhs){
	if(this != &rhs){
	}
	return(*this);
}

Span::Span(Span const & src){
	*this = src;
	return ;
}

const char *Span::FullVectorException::what() const throw()
{
	return ("The container is full");
}

const char *Span::FewNumbersException::what() const throw()
{
	return ("The container need to have at least 2 numbers");
}

unsigned int	Span::shortestSpan(){
	if (_vector.size() < 2)
		throw FewNumbersException();
	std::vector<int>::iterator end = _vector.end();
	std::vector<int>::iterator firstValue = _vector.begin();
	std::vector<int>::iterator secondValue = _vector.begin();
	long int	shortestSpan = 4294967295;
	secondValue++;
	while (secondValue != end){
		if (*secondValue - *firstValue < shortestSpan){
			shortestSpan = *secondValue - *firstValue;
		}
		firstValue++;
		secondValue++;
	}
	return (static_cast<unsigned int>(shortestSpan));
}

unsigned int	Span::longestSpan(){
	if (_vector.size() < 2)
		throw FewNumbersException();
	std::vector<int>::iterator end = _vector.end();
	end--;
	return (static_cast<unsigned int>(*end - *_vector.begin()));
}

void	Span::addNumber(int number){
	if (_vector.size() == this->_maxSize)
		throw FullVectorException();
	_vector.push_back(number);
	sort(_vector.begin(), _vector.end());
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (_vector.size() == this->_maxSize)
		throw FullVectorException();
	while (begin != end){
		if (_vector.size() == this->_maxSize){
			sort(_vector.begin(), _vector.end());
			throw FullVectorException();
		}
		_vector.push_back(*begin);
		begin++;
	}
	sort(_vector.begin(), _vector.end());
}

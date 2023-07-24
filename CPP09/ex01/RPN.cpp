/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:53:26 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/07 10:12:35 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _input("1 2 +"){
}

RPN::RPN(char *input){
	if (input == NULL){
		_input.assign("1 2 +");
	}
	else{
		_input.assign(input);
	}
}

RPN::~RPN(void){
}

RPN & RPN::operator=(RPN const & rhs){
	if(this != &rhs){
		this->_input = rhs._input;
		this->_stack = rhs._stack;
	}
	return(*this);
}

RPN::RPN(RPN const & src){
	*this = src;
	return ;
}

void	RPN::setInput(std::string input){
	this->_input.assign(input);
	while (!_stack.empty())
		_stack.pop();
}

bool	RPN::_validateInput(){
	size_t	i;
	size_t	difference;

	i = 0;
	difference = 0;
	if (_input.size() < 5)
		return (false);
	if (static_cast<std::string>("0123456789").find(_input[0]) == std::string::npos || static_cast<std::string>("0123456789").find(_input[2]) == std::string::npos)
		return (false);
	while (i != _input.size()){
		if (static_cast<std::string>("0123456789+/*-").find(_input[i]) == std::string::npos)
		{
			if ((i + 1) != _input.size() && _input[i + 1] != ' ')
				return (false);
		}
		if (static_cast<std::string>("+/*-").find(_input[i]) != std::string::npos)
			difference--;
		else
			difference++;
		if (difference < 1)
			return (false);
		if (i + 1 != _input.size())
			i += 2;
		else
			i++;
	}
	if (difference != 1)
		return (false);
	return (true);
}

void	RPN::_doOperation(char operation){
	int	firstNum;
	int	lastNum;

	lastNum = _stack.top();
	_stack.pop();
	firstNum = _stack.top();
	_stack.pop();
	switch(operation){
		case '+':
			_stack.push(firstNum + lastNum);
			break;
		case '-':
			_stack.push(firstNum - lastNum);
			break;
		case '*':
			_stack.push(firstNum * lastNum);
			break;
		case '/':
			if (lastNum == 0)
				throw DivisionByZeroException();
			_stack.push(firstNum / lastNum);
			break;
	}
}

void	RPN::calculate(){
	size_t	i;

	if (!this->_input[0]){
		std::cout << "Error: Input is empty" << std::endl;
		return ;
	}
	if (!_validateInput()){
		std::cout << "Error: Input is in wrong format" << std::endl;
		return ;
	}

	i = 4;
	_stack.push(_input[0] - '0');
	_stack.push(_input[2] - '0');
	while (i != _input.size()){
		if (static_cast<std::string>("+/*-").find(_input[i]) != std::string::npos)
			_doOperation(_input[i]);
		else
			_stack.push(_input[i] - '0');
		if (i + 1 != _input.size())
			i += 2;
		else
			i++;
	}
	std::cout << _stack.top() << std::endl;
}

const char *RPN::DivisionByZeroException::what() const throw(){
	return ("Error: tried to divide a number by zero");
};

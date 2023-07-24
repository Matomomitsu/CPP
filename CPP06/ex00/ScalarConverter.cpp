/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:07:23 by mtomomit          #+#    #+#             */
/*   Updated: 2023/07/05 01:59:44 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double ScalarConverter::_double = 0;
char	ScalarConverter::_char = 0;
float	ScalarConverter::_float = 0;
int	ScalarConverter::_int = 0;

void	ScalarConverter::_impossible(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool	ScalarConverter::_isDigit(char c) {
	return c >= '0' && c <= '9';
}

void	ScalarConverter::_printInf(int sign){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (sign == -1){
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
}

void	ScalarConverter::_printNan(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

bool	ScalarConverter::_verifyNanInf(std::string data){
	if (data == "-inf" || data == "-inff"){
		_printInf(-1);
		return (true);
	}
	if (data == "+inf" || data == "+inff" || data == "inf" || data == "inff"){
		_printInf(1);
		return (true);
	}
	if (data == "nan" || data == "nanf"){
		_printNan();
		return (true);
	}
	return (false);
}

void	ScalarConverter::convert(std::string data){
	size_t i = 0;

	if (data[i] == '-' || data[i] == '+')
		i++;
	if (_verifyNanInf(data))
		return ;
	while (_isDigit(data[i]))
	{
		i++;
		if (data[i] == '.')
		{
			_float = 1;
			i++;
			while (_isDigit(data[i]))
				i++;
		}
	}
	if (!_isDigit(data[i]) && i == 0 && data[i + 1] == '\0')
		_charConverter(data);
	else if ((data[i] != '\0' && data[i] != 'f') || (data[i] == 'f' && data[i + 1] != '\0'))
		_impossible();
		else if (_float == 1)
			_floatConverter(data);
			else
				_intConverter(data);
}

void	ScalarConverter::_charConverter(std::string data){
	_char = data[0];
	if (_char < 33 || _char == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << _char << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(_char) << std::endl;
	std::cout << "float: " << static_cast<float>(_char) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(_char) << std::endl;
}

void	ScalarConverter::_intConverter(std::string data){
	long int	longInt;

	longInt = std::atol(data.c_str());
	if (longInt < -(2147483648) || longInt > 2147483647)
	{
		_floatConverter(data);
		return ;
	}
	_int = std::atof(data.c_str());
	if (_int > -1 && _int < 128){
				if (_int < 33 || _int == 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: \'" << static_cast<char>(_int) << "\'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << static_cast<float>(_int) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(_int) << ".0" << std::endl;
}

void	ScalarConverter::_doubleConverter(std::string data){
	_double = std::atof(data.c_str());
	if (_double == std::numeric_limits<double>::infinity() || _double == std::numeric_limits<double>::quiet_NaN())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
}

void	ScalarConverter::_floatConverter(std::string data){
	_float = std::atof(data.c_str());
	if (_float == std::numeric_limits<float>::infinity() || _float == std::numeric_limits<float>::quiet_NaN())
		_doubleConverter(data);
	else{
		if (_float > -1 && _float < 128)
		{
			if (_float < 33 || static_cast<int>(_float) == 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: \'" << static_cast<char>(_float) << "\'" << std::endl;
			std::cout << "int: " << static_cast<int>(_float) << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			long int	longInt = std::atol(data.c_str());
			if (longInt <= 2147483647 && longInt >= -2147483648)
				std::cout << "int: " << static_cast<int>(_float) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
		}
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(_float) << std::endl;
	}
}

ScalarConverter::~ScalarConverter(void){
}

ScalarConverter::ScalarConverter(void){
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){
	if(this != &rhs){
	}
	return(*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const & src){
	*this = src;
	return ;
}

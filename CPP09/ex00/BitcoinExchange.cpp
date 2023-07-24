/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:38 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/07 10:11:54 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::_validateDate(std::string date){
	std::tm				tmDate = {};
	char				*parsedDate;
	int					daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	parsedDate = strptime(date.c_str(), "%Y-%m-%d", &tmDate);
	int	year = tmDate.tm_year + 1900;
	int	month = tmDate.tm_mon + 1;
	int	day = tmDate.tm_mday;
	if (month < 1 || month > 12)
		return (false);
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	if (parsedDate[0] != '\0')
		return (false);
	return (true);
}

bool	BitcoinExchange::_isDigit(char c) {
	return c >= '0' && c <= '9';
}

void	BitcoinExchange::_validateDatabase(std::string line){
	size_t	pos;
	std::string	date;
	std::string price;
	float	fPrice;
	size_t	i;

	pos = line.find(',');
	if (pos == std::string::npos)
		throw InvalidDatabaseFormatException();
	date = line.substr(0, pos);
	if (!_validateDate(date))
		throw InvalidDateFormatException();
	price = line.substr(pos + 1, line.length() - pos - 1);
	i = 0;
	while (_isDigit(price[i]))
	{
		i++;
		if (price[i] == '.')
		{
			i++;
			while (_isDigit(price[i]))
				i++;
		}
	}
	if (price[i])
		throw InvalidPriceException();
	fPrice = atof(price.c_str());
	_btcMap.insert(std::pair<std::string, float>(date, fPrice));
}

BitcoinExchange::BitcoinExchange(void){
	std::string	line;
	std::ifstream	database(static_cast<std::string>("data.csv").c_str());
	if (!database.is_open())
		throw OpenDatabaseErrorException();
	std::getline(database, line);
	if (line != "date,exchange_rate")
		throw InvalidDatabaseHeaderException();
	while (std::getline(database, line)){
		try{
			_validateDatabase(line);
		}
		catch (const InvalidDateFormatException &e){
			std::string	date;
			size_t	pos;
			pos = line.find(',');
			date = line.substr(0, pos);
			std::cerr << e.what();
			std::cerr << "in database => ";
			std::cerr << date << std::endl;
			throw DatabaseErrorException();
		}
		catch (const InvalidPriceException &e){
			std::string price;
			size_t	pos;
			pos = line.find(',');
			price = line.substr(pos + 1, line.length() - pos - 1);
			std::cerr << e.what();
			std::cerr << "in database => ";
			std::cerr << price << std::endl;
			throw DatabaseErrorException();
		}
		catch(std::exception &e){
			std::cerr << e.what();
			std::cerr << line << std::endl;
			throw DatabaseErrorException();
		}
	}
}

bool	BitcoinExchange::_validateNumber(std::string number){
	size_t	i;
	float	fNumber;

	i = 0;
	while (_isDigit(number[i]))
	{
		i++;
		if (number[i] == '.')
		{
			i++;
			while (_isDigit(number[i]))
				i++;
		}
	}
	if (number[i] && number[i] != '-')
	{
		std::cerr << "Error: not a number => " << number << std::endl;
		return (false);
	}
	if (number[i] == '-')
	{
		std::cerr << "Error: not a positive number => " << number << std::endl;
		return (false);
	}
	fNumber = atof(number.c_str());
	if (fNumber > 1000)
	{
		std::cerr << "Error: too large a number  => " << number << std::endl;
		return (false);
	}
	return (fNumber);
}

void	BitcoinExchange::_validateFile(std::string line){
	size_t	pos;
	std::string	date;
	std::string number;
	float		fNumber;
	std::map<std::string, float>::iterator it;

	pos = line.find('|');
	if (pos == std::string::npos){
		std::cerr << "Error: bad input invalid format in input file => " << line << std::endl;
		return ;
	}
	date = line.substr(0, pos - 1);
	if (!_validateDate(date)){
		std::cerr << "Error: bad input invalid date in input file => " << date << std::endl;
		return ;
	}
	number = line.substr(pos + 2, line.length() - pos - 2);
	if (!_validateNumber(number))
		return ;
	fNumber = atof(number.c_str());
	it = _btcMap.upper_bound(date);
	if (it != _btcMap.begin())
		it--;
	std::cout << date << " => " << fNumber << " = " << it->second * fNumber << std::endl;
}

void	BitcoinExchange::convertFile(char *file){
	std::string	line;
	std::ifstream	iFile(file);
	if (!iFile.is_open())
		throw OpenFileErrorException();
	std::getline(iFile, line);
	if (line != "date | value")
		throw InvalidFileHeaderException();
	while (std::getline(iFile, line)){
			_validateFile(line);
	}
}

BitcoinExchange::~BitcoinExchange(void){
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){
	if(this != &rhs){
		this->_btcMap = rhs._btcMap;
	}
	return(*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){
	*this = src;
	return ;
}

// Exceptions
const char *BitcoinExchange::InvalidDatabaseHeaderException::what() const throw(){
	return ("Error: Invalid Header of database should be \"date,exchange_rate\"\n");
}

const char *BitcoinExchange::OpenDatabaseErrorException::what() const throw(){
	return ("Error: Could not open data.csv database\n");
};

const char *BitcoinExchange::InvalidDatabaseFormatException::what() const throw(){
	return ("Error: Element of database is in invalid format => ");
};

const char *BitcoinExchange::InvalidFileHeaderException::what() const throw(){
	return ("Error: Invalid Header of input file should be \"date | value\"\n");
}

const char *BitcoinExchange::OpenFileErrorException::what() const throw(){
	return ("Error: Could not open input file\n");
};

const char *BitcoinExchange::InvalidDateFormatException::what() const throw(){
	return ("Error: bad input invalid date ");
};

const char *BitcoinExchange::InvalidPriceException::what() const throw(){
	return ("Error: bad input invalid price ");
};

const char *BitcoinExchange::DatabaseErrorException::what() const throw(){
	return ("");
};

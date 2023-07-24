/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:48 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/09 23:40:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <fstream>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		virtual ~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
		BitcoinExchange(BitcoinExchange const & src);

		void	convertFile(char *file);

		class	DatabaseErrorException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	InvalidDatabaseHeaderException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	OpenDatabaseErrorException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	InvalidDatabaseFormatException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	InvalidDateFormatException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	InvalidPriceException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	InvalidFileHeaderException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class	OpenFileErrorException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

	private:
		bool	_isDigit(char c);
		void	_validateDatabase(std::string line);
		void	_validateFile(std::string line);
		bool	_validateDate(std::string date);
		bool	_validateNumber(std::string number);
		std::map<std::string, float>	_btcMap;
};

#endif

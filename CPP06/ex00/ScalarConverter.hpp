/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:07:25 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/25 13:44:45 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <stdlib.h>
# include <iostream>
# include <cmath>
# include <limits>

class ScalarConverter {
	public:
		static void	convert(std::string data);

	private:
		static void	_impossible();
		static bool	_isDigit(char c);
		static bool	_verifyNanInf(std::string data);
		static void	_printInf(int sign);
		static void	_printNan();
		static void	_charConverter(std::string data);
		static void	_intConverter(std::string data);
		static void	_floatConverter(std::string data);
		static void	_doubleConverter(std::string data);
		ScalarConverter(void);
		virtual ~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const & rhs);
		ScalarConverter(ScalarConverter const & src);
		static double _double;
		static char	_char;
		static float	_float;
		static int	_int;
};

#endif

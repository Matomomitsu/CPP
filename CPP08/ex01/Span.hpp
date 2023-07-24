/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:53 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/21 16:29:06 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span {
	public:
		Span(void);
		Span(unsigned int maxSize);
		virtual ~Span(void);
		Span & operator=(Span const & rhs);
		Span(Span const & src);
		class	FullVectorException : public std::exception{
			virtual const char *what() const throw();
		};
		class	FewNumbersException : public std::exception{
			virtual const char *what() const throw();
		};
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	addNumber(int number);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	private:
		unsigned int	_maxSize;
		std::vector<int>	_vector;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:53:34 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/07 10:12:40 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <stack>
#include <iostream>

class RPN {
	public:
		RPN(void);
		RPN(char *input);
		virtual ~RPN(void);
		RPN & operator=(RPN const & rhs);
		RPN(RPN const & src);

		void	setInput(std::string input);
		void	calculate();

		class	DivisionByZeroException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

	private:
		bool	_validateInput();
		void	_doOperation(char op);
		std::stack<int> _stack;
		std::string		_input;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:06 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat(void);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		Bureaucrat(Bureaucrat const & src);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		int		getGrade() const;
		std::string	getName() const;
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form);

	private:
		std::string	const _name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif

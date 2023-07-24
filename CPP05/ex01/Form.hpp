/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:54 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define MIN_GRADE 150
# define MAX_GRADE 1

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string const name, int const signGrade, int const execGrade);
		virtual ~Form(void);
		Form & operator=(Form const & rhs);
		Form(Form const & src);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		void	beSigned(Bureaucrat const &bureaucrat);

	private:
		std::string const	_name;
		bool		_isSigned;
		int const	_gradeToSign;
		int const	_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, Form const &i);

#endif

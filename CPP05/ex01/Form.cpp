/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Form"), _isSigned(false), _gradeToSign(MAX_GRADE), _gradeToExec(MAX_GRADE){
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExec(execGrade){
	if (signGrade < MAX_GRADE || signGrade > MIN_GRADE)
		const_cast<int&>(this->_gradeToSign) = MAX_GRADE;
	if (execGrade < MAX_GRADE || execGrade > MIN_GRADE)
		const_cast<int&>(this->_gradeToExec) = MAX_GRADE;
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw Form::GradeTooLowException();

}

Form::~Form(void){
}

Form & Form::operator=(Form const & rhs){
	if(this != &rhs){
		this->_isSigned = rhs.getSigned();
	}
	return(*this);
}

Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec){
	*this = src;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::string const	Form::getName() const{
	return (this->_name);
}

bool	Form::getSigned() const{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const{
	return (this->_gradeToExec);
}

void	Form::beSigned(Bureaucrat const &bureaucrat){
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream	&operator<<(std::ostream &o, Form const &i){
	bool formSigned = i.getSigned();

	if (formSigned){
		o << i.getName() << " Form require " << i.getGradeToSign() << " to be signed and " <<
		i.getGradeToExec() << " to be executed " << std::endl;
		o << "Form is already signed" << std::endl;
	}
	else{
		o << i.getName() << " Form require " << i.getGradeToSign() << " to be signed and " <<
		i.getGradeToExec() << " to be executed " << std::endl;
		o << "Form isn\'t signed" << std::endl;
	}
	return (o);
}

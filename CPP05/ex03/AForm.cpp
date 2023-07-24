/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:38:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/14 20:39:59 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _target("undefined"), _name("Form"), _isSigned(false), _gradeToSign(MAX_GRADE), _gradeToExec(MAX_GRADE){
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade, std::string const target) :
	 _target(target), _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExec(execGrade)
{
	if (signGrade < MAX_GRADE || signGrade > MIN_GRADE)
		const_cast<int&>(this->_gradeToSign) = MAX_GRADE;
	if (execGrade < MAX_GRADE || execGrade > MIN_GRADE)
		const_cast<int&>(this->_gradeToExec) = MAX_GRADE;
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();

}

AForm::~AForm(void){
}

AForm & AForm::operator=(AForm const & rhs){
	if(this != &rhs){
		this->_isSigned = rhs.getSigned();
		this->_target = rhs.getTarget();
	}
	return(*this);
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	*this = src;
	return ;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::string const	AForm::getName() const{
	return (this->_name);
}

bool	AForm::getSigned() const{
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const{
	return (this->_gradeToExec);
}

std::string	AForm::getTarget() const{
	return (this->_target);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat){
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream	&operator<<(std::ostream &o, AForm const &i){
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

void	AForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
}

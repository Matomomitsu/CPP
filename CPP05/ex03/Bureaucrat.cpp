/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:04 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(MIN_GRADE){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < MAX_GRADE || grade > MIN_GRADE)
		this->_grade = MIN_GRADE;
	else
		this->_grade = grade;
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void){
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	if(this != &rhs){
		this->_grade = rhs.getGrade();
		const_cast<std::string&>(this->_name) = rhs._name;
	}
	return(*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name){
	*this = src;
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureacrat Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureacrat Grade is too low");
}

int		Bureaucrat::getGrade() const{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const{
	return (this->_name);
}

void	Bureaucrat::incrementGrade(){
	if (this->_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(){
	if (this->_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form){
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception const &e){
		std::cout << this->getName() << " couldn\'t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception const &e){
		std::cout << this->getName() << " couldn\'t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}

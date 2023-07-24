/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:08:12 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE, "undefined"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE, target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
	if(this != &rhs){
		const_cast<std::string&>(this->_target) = rhs.getTarget();
	}
	return(*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE, src.getTarget())
{
	*this = src;
	return ;
}

const char* ShrubberyCreationForm::FileCreateErrorException::what() const throw()
{
	return ("File couldn\'t be created");
}

const char* ShrubberyCreationForm::FileWriteErrorException::what() const throw()
{
	return ("Couldn\'t write in the file");
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::string	filename = this->getTarget() + "_shrubbery";
	std::ofstream	ofs;
	ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
		throw ShrubberyCreationForm::FileCreateErrorException();
	ofs << SHRUBBERY_TREE;
	if (ofs.bad())
		throw ShrubberyCreationForm::FileWriteErrorException();
	ofs.close();
}

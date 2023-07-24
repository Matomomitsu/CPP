/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:09:21 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE, "undefined"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE, target){
}

PresidentialPardonForm::~PresidentialPardonForm(void){
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	if(this != &rhs){
		this->_target = rhs.getTarget();
	}
	return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE, src.getTarget()){
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod BeebleBrox" << std::endl;
}

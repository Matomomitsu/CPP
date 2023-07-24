/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:09:27 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE, "undefined"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE, target){
}

RobotomyRequestForm::~RobotomyRequestForm(void){
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
	if(this != &rhs){
		this->_target = rhs.getTarget();
	}
	return(*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE, src.getTarget()){
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	const short random = rand() % 2;

	AForm::execute(executor);
	if (random)
		std::cout << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:11:38 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){

}

Intern::~Intern(void){
}

Intern & Intern::operator=(Intern const & rhs){
	if(this != &rhs){
	}
	return(*this);
}

Intern::Intern(Intern const & src){
	*this = src;
	return ;
}

AForm *newPresidentialPardonForm(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm *newRobotomyRequestForm(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm *newShrubberyCreationForm(std::string target){
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const name, std::string target){
	std::string formName[FORMS_AMOUNT] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*funcPtr[FORMS_AMOUNT])(std::string target) = {newShrubberyCreationForm, newRobotomyRequestForm ,newPresidentialPardonForm};

	for (int i = 0; i < FORMS_AMOUNT; i++){
		if (name == formName[i]){
			std::cout << "Intern creates " << formName[i] << std::endl;
			return ((funcPtr[i])(target));
		}
	}
	std::cout << "Intern couldn\'t create " << name << std::endl;
	return (NULL);
}

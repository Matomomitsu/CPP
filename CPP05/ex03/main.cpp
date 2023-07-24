/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Intern intern;
	{
		std::cout << '\n';
		srand(time(NULL));
		AForm *scf = intern.makeForm("shrubbery creation", "home");
		Bureaucrat bill("Bill", 1), don("Don", 145), gabe("Gabe", 150);
		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< *scf;
		gabe.signForm(*scf);
		gabe.executeForm(*scf);
		don.signForm(*scf);
		don.executeForm(*scf);
		bill.executeForm(*scf);
		delete scf;
	}
	{
		std::cout << '\n';
		AForm *rrf = intern.makeForm("robotomy request", "BOT");
		Bureaucrat bill("bill", 1), don("Don", 71), gabe("Gabe", 150);
		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< *rrf;
		gabe.signForm(*rrf);
		gabe.executeForm(*rrf);
		don.signForm(*rrf);
		don.executeForm(*rrf);
		bill.executeForm(*rrf);
		bill.executeForm(*rrf);
		bill.executeForm(*rrf);
		bill.executeForm(*rrf);
		bill.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << '\n';
		AForm *ppf = intern.makeForm("presidential pardon", "Douglas Adams");
		Bureaucrat bill("bill", 1), don("Don", 24), gabe("Gabe", 150);
		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< *ppf;
		gabe.signForm(*ppf);
		gabe.executeForm(*ppf);
		don.signForm(*ppf);
		don.executeForm(*ppf);
		bill.executeForm(*ppf);
		delete ppf;
	}
	intern.makeForm("undefined", "undefined");
	std::cout << '\n';
	return (0);
}

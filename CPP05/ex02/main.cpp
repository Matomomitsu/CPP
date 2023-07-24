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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		srand(time(NULL));
		ShrubberyCreationForm        scf("Home");
		Bureaucrat bill("Bill", 1), don("Don", 145), gabe("Gabe", 150);

		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< scf;
		gabe.signForm(scf);
		gabe.executeForm(scf);
		don.signForm(scf);
		don.executeForm(scf);
		bill.executeForm(scf);
	}
	{
		RobotomyRequestForm        rrf("BOT");
		Bureaucrat bill("bill", 1), don("Don", 71), gabe("Gabe", 150);

		std::cout << '\n';
		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< rrf;
		gabe.signForm(rrf);
		gabe.executeForm(rrf);
		don.signForm(rrf);
		don.executeForm(rrf);
		bill.executeForm(rrf);
		bill.executeForm(rrf);
		bill.executeForm(rrf);
		bill.executeForm(rrf);
		bill.executeForm(rrf);
	}
	{
		PresidentialPardonForm        ppf("Douglas Adams");
		Bureaucrat bill("bill", 1), don("Don", 24), gabe("Gabe", 150);

		std::cout << '\n';
		std::cout << bill << '\n'
					<< don << '\n'
					<< gabe << '\n'
					<< ppf;
		gabe.signForm(ppf);
		gabe.executeForm(ppf);
		don.signForm(ppf);
		don.executeForm(ppf);
		bill.executeForm(ppf);
	}
	return (0);
}

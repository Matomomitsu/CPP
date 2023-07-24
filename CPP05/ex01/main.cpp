/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/14 20:43:28 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form("Form", 50, 10);

	std::cout << form;

	Bureaucrat bill("bill", 100);
	Bureaucrat bill2("bill2", 50);
	std::cout << bill << std::endl;
	std::cout << bill2 << std::endl;

	bill.signForm(form);
	std::cout << form;

	bill2.signForm(form);
	std::cout << form;

	try
	{
		std::cout << "Trying to create a form with execGrade 0" << std::endl;
		Form FormGradeToHigh("FormGradeToHigh", 10, 0);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << " so was changed to " << MAX_GRADE << '\n';
	}
	try
	{
		std::cout << "Trying to create a form with signGrade 151" << std::endl;
		Form FormGradeToLow("FormGradeToLow", 151, 10);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << " so was changed to " << MAX_GRADE << '\n';
	}
	return (0);
}

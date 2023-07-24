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

int main(void)
{
	{
		try{
			Bureaucrat bill("bill", 150);
			std::cout << bill << std::endl;
			std::cout << "Trying to decrement bill" << std::endl;
			bill.decrementGrade();
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat bill("bill", 1);
			std::cout << bill << std::endl;
			std::cout << "Trying to increment bill" << std::endl;
			bill.incrementGrade();
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			std::cout << "Trying to create a bureaucrat with 0 of grade" << std::endl;
			Bureaucrat bill("bill", 0);
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			std::cout << "Trying to create a bureaucrat with 151 of grade" << std::endl;
			Bureaucrat bill("bill", 151);
		}
		catch (const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		Bureaucrat bill("bill", 150);
		std::cout << bill << std::endl;
		bill.incrementGrade();
		std::cout << bill << std::endl;
		bill.decrementGrade();
		std::cout << bill << std::endl;
	}
	return 0;
}

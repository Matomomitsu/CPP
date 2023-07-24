/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:50:42 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 02:34:13 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl	Harl;

	std::cout << "[ DEBUG ]" << std::endl;
	Harl.complain("DEBUG");
	std::cout << "[ INFO ]" << std::endl;
	Harl.complain("INFO");
	std::cout << "[ WARNING ]" << std::endl;
	Harl.complain("WARNING");
	std::cout << "[ ERROR ]" << std::endl;
	Harl.complain("ERROR");
	std::cout << "Testing: Invalid input" << std::endl;
	Harl.complain("debug");
}

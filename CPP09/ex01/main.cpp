/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:53:19 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/07 10:12:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	try{
		rpn.calculate();
		std::cout << "Setting input to '8 9 * 9 - 9 - 9 - 4 - 1 +'" << std::endl;
		rpn.setInput("8 9 * 9 - 9 - 9 - 4 - 1 +");
		rpn.calculate();
		std::cout << "Setting input to '7 7 * 7 -'" << std::endl;
		rpn.setInput("7 7 * 7 -");
		rpn.calculate();
		std::cout << "Setting input to '1 2 * 2 / 2 * 2 4 - +'" << std::endl;
		rpn.setInput("1 2 * 2 / 2 * 2 4 - +");
		rpn.calculate();
		std::cout << "Setting input to '3 4 + 5 * 6 - 2 8 * 1 + 9 / 7 3 * 6 2 * - + 5 8 * 4 9 * - - -'" << std::endl;
		rpn.setInput("3 4 + 5 * 6 - 2 8 * 1 + 9 / 7 3 * 6 2 * - + 5 8 * 4 9 * - - -");
		rpn.calculate();
		std::cout << "Setting input to '(1 + 1)'" << std::endl;
		rpn.setInput("(1 + 1)");
		rpn.calculate();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}

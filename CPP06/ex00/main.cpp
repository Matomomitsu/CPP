/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:16:39 by mtomomit          #+#    #+#             */
/*   Updated: 2023/07/05 00:19:36 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc == 1)
		std::cerr << "Should give one argument" << std::endl;
	else if (argc > 2)
		std::cerr << "Should give only one argument" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return (0);
}

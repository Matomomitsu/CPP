/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:22:25 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/07 10:12:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2){
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	if (argc != 2){
		std::cerr << "Program expected only one input" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange bitcoin;
		bitcoin.convertFile(argv[1]);
	}
	catch (std::exception &e){
		std::cerr << e.what();
	}
}

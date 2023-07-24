/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:00 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/30 13:07:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	std::vector<int> vector;
	vector.push_back(45);
	vector.push_back(99);
	vector.push_back(88);
	vector.push_back(20);
	vector.push_back(321);
	vector.push_back(562);
	Span sp = Span(5);
	try {
			sp.shortestSpan();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	sp.addNumber(6);
	sp.addNumber(3);
	try {
			sp.addNumbers(vector.begin(), vector.end());
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

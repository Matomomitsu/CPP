/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:38:00 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

	std::cout << "\nTest aritmetic operators" << std::endl;
    std::cout << "a + b is " << a + b << std::endl;
    std::cout << "a - b is " << a - b << std::endl;
    std::cout << "a * b is " << a * b << std::endl;
    std::cout << "a / b is " << a / b << std::endl;

	std::cout << "\nTest comparison operators" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "\nTest min and max functions" << std::endl;
    std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;

	std::cout << "\nTest increment and decrement operators" << std::endl;
	Fixed e;
	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;
	std::cout << e-- << std::endl;
	std::cout << e << std::endl;
	std::cout << --e << std::endl;
	std::cout << e << std::endl;

    return 0;
}

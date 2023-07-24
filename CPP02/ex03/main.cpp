/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:23:34 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 03:49:33 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

void testInside() {
    Point a(-7,0);
	Point b(-3.28, -2.41);
	Point c(-3, 2);
	Point point(-5,1);

	std::cout << "Testing with -7,0 ; -3.28,-2.41 ; -3,2 ; -5,1" << std::endl;
	if (bsp(a, b, c, point)) {
		std::cout << "Point is inside" << std::endl;
	}
	else {
		std::cout << "Point is not inside" << std::endl;
	}

	Point d(-7,0);
	Point e(-3.0, 0);
	Point f(-5, 1.23);
	std::cout << "Testing with -7,0 ; -3.0,0 ; -5,1.23 ; -5,1" << std::endl;
	if (bsp(d, e, f, point)) {
		std::cout << "Point is inside" << std::endl;
	}
	else {
		std::cout << "Point is not inside" << std::endl;
	}
}

void testNotInside() {
    Point a(-7,0);
	Point b(-3.28, -2.41);
	Point c(-2, 2);
	Point point(-5,1);

	std::cout << "Testing with -7,0 ; -3.28,-2.41 ; -2,2 ; -5,1" << std::endl;
	if (bsp(a, b, c, point)) {
		std::cout << "Point is inside" << std::endl;
	}
	else {
		std::cout << "Point is not inside" << std::endl;
	}

	Point d(-7,0);
	Point e(-3.0, 0);
	Point f(-4.98, 0.77);
	std::cout << "Testing with -7,0 ; -3.0,0 ; -4.98,0.77 ; -5,1" << std::endl;
	if (bsp(d, e, f, point)) {
		std::cout << "Point is inside" << std::endl;
	}
	else {
		std::cout << "Point is not inside" << std::endl;
	}
}

int main() {
	testInside();
	testNotInside();
	return 0;
}

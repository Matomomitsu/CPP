/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:17:39 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/19 20:08:49 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(void) {
	{
		Array<int> myArray(5);
		int *intArray = new int[5];
		for (int i = 0; i < 5; i++) {
		const int value = i;
		myArray[i] = value;
		intArray[i] = value;
		}

		std::cout << "myArray size: " << myArray.size() << std::endl;

		std::cout << "myArray:";
		for (int i = 0; i < 5; i++)
			std::cout << ' ' << myArray[i];
		std::cout << std::endl;

		std::cout << "intArray:";
		for (int i = 0; i < 5; i++)
		std::cout << ' ' << intArray[i];
		std::cout << std::endl;

		std::cout << "TESTING DEEP COPY" << std::endl;
		std::cout << "Copying myArray" << std::endl;
		Array<int> copyArray(myArray);
		std::cout << "copyArray:";
		for (int i = 0; i < 5; i++)
		std::cout << ' ' << copyArray[i];
		std::cout << std::endl;
		std::cout << "Changed copyArray:";
		for (int i = 0; i < 5; i++) {
			const int value = i + 5;
			copyArray[i] = value;
			std::cout << ' ' << copyArray[i];
		}
		std::cout << std::endl;
		std::cout << "Myarray:";
		for (int i = 0; i < 5; i++)
			std::cout << ' ' << myArray[i];
		std::cout << std::endl;
		std::cout << "TESTING INDEX OUT OF BOUNDS" << std::endl;
		try {
			myArray[-2] = 0;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		delete[] intArray;
	}
	{
		std::cout << "TESTING WITH A CONST ARRAY" << std::endl;
		const Array<int> myArray(5);
		int *intArray = new int[5];
		for (int i = 0; i < 5; i++) {
		const int value = i;
		myArray[i] = value;
		intArray[i] = value;
		}

		std::cout << "myArray size: " << myArray.size() << std::endl;

		std::cout << "myArray:";
		for (int i = 0; i < 5; i++)
			std::cout << ' ' << myArray[i];
		std::cout << std::endl;

		std::cout << "intArray:";
		for (int i = 0; i < 5; i++)
		std::cout << ' ' << intArray[i];
		std::cout << std::endl;

		std::cout << "TESTING DEEP COPY" << std::endl;
		std::cout << "Copying myArray" << std::endl;
		Array<int> copyArray(myArray);
		std::cout << "copyArray:";
		for (int i = 0; i < 5; i++)
		std::cout << ' ' << copyArray[i];
		std::cout << std::endl;
		std::cout << "Changed copyArray:";
		for (int i = 0; i < 5; i++) {
			const int value = i + 5;
			copyArray[i] = value;
			std::cout << ' ' << copyArray[i];
		}
		std::cout << std::endl;
		std::cout << "Myarray:";
		for (int i = 0; i < 5; i++)
			std::cout << ' ' << myArray[i];
		std::cout << std::endl;
		std::cout << "TESTING INDEX OUT OF BOUNDS" << std::endl;
		try {
			myArray[-2] = 0;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		delete[] intArray;
	}
	return 0;
}

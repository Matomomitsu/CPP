/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:32:41 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/21 16:06:12 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void	print(T const &x){
	std::cout << x << " ";
}

int main() {
	const int tab[] = { 0, 1, 2, 3, 4};
	float floatTab[] = { 0.0, 1.1, 2.2, 3.3, 4.4};
	std::string strings[] = {"Hello", "World"};

	std::cout << "int array = ";
	iter(tab, 5, print<int>);
	std::cout << std::endl;
	std::cout << "strings array = ";
	iter(strings, 2, print<std::string>);
	std::cout << std::endl;
	std::cout << "float array = ";
	iter(floatTab, 5, print<float>);
	std::cout << std::endl;

	return 0;
}

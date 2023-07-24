/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:09:35 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/19 20:01:39 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(){
	{
		int	x = 2;
		int	y = 4;

		::swap(x, y);
		std::cout << "x = " << x << "\ny = " << y << std::endl;
		std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
		std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	}
	{
		const float	x = 42.42;
		const float	y = 41.41;

		std::cout << "x = " << x << "\ny = " << y << std::endl;
		std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
		std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	}
	{
		std::string	x = "X string";
		std::string	y = "Y string";

		::swap(x, y);
		std::cout << "x = " << x << "\ny = " << y << std::endl;
		std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
		std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	}
	{
		std::string	x = "X string";
		std::string	y = "X string";

		::swap(x, y);
		std::cout << "x = " << x << "\ny = " << y << std::endl;
		std::cout << "y address " << &y << std::endl;
		std::cout << "result address max(x, y) = " << &::max(x, y) << std::endl;
		std::cout << "result address min(x, y) = " << &::min(x, y) << std::endl;
	}
}

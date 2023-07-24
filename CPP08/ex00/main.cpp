/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:26:01 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/21 16:26:27 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::vector<int>	vector;
		std::vector<int>::iterator iterator;

		for (int i = 0; i < 20; i++)
			vector.push_back(i);
		iterator = ::easyfind(vector, 5);
		std::cout << *iterator << std::endl;
	}
	{
		std::deque<int>	deque;
		std::deque<int>::iterator iterator;

		for (int i = 0; i < 20; i++)
			deque.push_front(i);
		try{
			iterator = ::easyfind(deque, 0);
			std::cout << *iterator << std::endl;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::list<int>	list;
		std::list<int>::iterator iterator;

		for (int i = 0; i < 20; i++)
			list.push_front(i);
		try{
			iterator = ::easyfind(list, -2);
			std::cout << *iterator << std::endl;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
}

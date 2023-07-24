/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:07:49 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/21 16:36:32 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "PDF TEST\n" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "CHECK LAST ELEMENT ADDED" << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "CHECK CURRENT SIZE" << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "PRINT CURRENT STACK" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "PDF TEST CHANGED TO A LIST\n" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "CHECK LAST ELEMENT ADDED" << std::endl;
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << "CHECK CURRENT SIZE" << std::endl;
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		std::cout << "PRINT CURRENT LIST" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:57:30 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/09 23:48:45 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base	*generate(void){
	int random = std::rand() % 3;

	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void	identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer to A class" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer to B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer to C class" << std::endl;
}

void	identify(Base &p){
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Reference to A class" << std::endl;
		return;
	}
	catch (std::exception &){
	}
	try{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Reference to B class" << std::endl;
		return;
	}
	catch (std::exception &){
	}
	try{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Reference to C class" << std::endl;
		return;
	}
	catch (std::exception &){
	}
}

int main(){
	std::srand(std::time(NULL));
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}

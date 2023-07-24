/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 17:17:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* horse = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << "Animal dog type: " << dog->getType() << std::endl;
		std::cout << "Animal cat type: "<< cat->getType() << std::endl;
		std::cout << "Animal cat sound: ";
		cat->makeSound();
		std::cout << "Animal dog sound: ";
		dog->makeSound();
		std::cout << "Animal horse sound: ";
		horse->makeSound();
		delete dog;
		delete cat;
		delete horse;
	}

	{
		const	WrongAnimal* wrongCat = new WrongCat();
		std::cout << "WrongAnimal wrongCat type: " << wrongCat->getType() << std::endl;
		std::cout << "WrongAnimal wrongCat sound: ";
		wrongCat->makeSound();
		delete wrongCat;
	}

	{
		std::cout << "Initializing without a pointer of Animal:" << std::endl;
		Dog dog;
		std::cout << "Dog sound: ";
		dog.makeSound();
		Cat cat;
		std::cout << "Cat sound: ";
		cat.makeSound();
		Animal animal;
		std::cout << "Animal sound: ";
		animal.makeSound();

		std::cout << "Initializing without a pointer of WrongAnimal:" << std::endl;
		WrongCat wrongCat;
		std::cout << "WrongCat sound: ";
		wrongCat.makeSound();
	}
	return 0;
}

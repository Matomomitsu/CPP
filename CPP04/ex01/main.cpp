/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:20 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 20:04:50 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
		std::cout << std::endl;
	}

	{
		Dog *dog  = new Dog();
		dog->setIdea(0, "TEST");
		Dog *dog2 = new Dog(*dog);
		std::cout << "TESTING DEEP COPY" << std::endl;
		std::cout << "Idea 0 of dog1: " << dog->getIdea(0) << std::endl;
		std::cout << "Idea 0 of dog2: " << dog2->getIdea(0) << std::endl;
		dog2->setIdea(0, "TEST DOG2");
		std::cout << "CHANGING IDEA 0 of DOG2" << std::endl;
		std::cout << "Idea 0 of dog1: " << dog->getIdea(0) << std::endl;
		std::cout << "Idea 0 of dog2: " << dog2->getIdea(0) << std::endl;
		delete dog;
		delete dog2;
		std::cout << std::endl;
	}

	{
		int numAnimals;
		int i;

		i = 0;
		numAnimals = 16;
		Animal *animals[numAnimals];
		while (i < numAnimals / 2)
		{
			animals[i++] = new Dog();
			reinterpret_cast<Dog *>(animals[i - 1])->setIdea(0, "I'm a dog");
		}
		while (i < numAnimals)
		{
			animals[i++] = new Cat();
			reinterpret_cast<Cat *>(animals[i - 1])->setIdea(0, "I'm a cat");
		}
		i = 0;
		while (i < numAnimals)
		{
			if (dynamic_cast<Dog *>(animals[i]))
				std::cout << reinterpret_cast<Dog *>(animals[i])->getIdea(0) << std::endl;
			else
				std::cout << reinterpret_cast<Cat *>(animals[i])->getIdea(0) << std::endl;
			delete animals[i++];
		}
		return 0;
	}
}

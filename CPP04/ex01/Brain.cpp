/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:58:38 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/13 19:46:18 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain was created (Brain constructor)" << std::endl;
}

Brain::~Brain(void){
	std::cout << "Brain was destructed (Brain destructor)" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs){
	int	i;

	i = 0;
	std::cout << "Brain Copy assigment operator called" << std::endl;
	if(this != &rhs){
		while (i < 100)
		{
			ideas[i] = rhs.ideas[i];
			i++;
		}
	}
	return(*this);
}

Brain::Brain(Brain const & src){
	std::cout << "Brain was created (Brain copy constructor)" << std::endl;
	*this = src;
	return ;
}

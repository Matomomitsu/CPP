/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:55 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/13 16:25:17 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal & operator=(Animal const & rhs);
		Animal(Animal const & src);
		std::string	getType() const;
		virtual void	makeSound() const;
	protected:
		std::string	_type;
};

#endif

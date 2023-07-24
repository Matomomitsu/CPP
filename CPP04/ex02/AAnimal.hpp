/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:13:55 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/13 16:34:45 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal {
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal & operator=(AAnimal const & rhs);
		AAnimal(AAnimal const & src);
		std::string	getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string	_type;
};

#endif

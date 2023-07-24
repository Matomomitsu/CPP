/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:13:23 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/18 14:45:20 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal & operator=(WrongAnimal const & rhs);
		WrongAnimal(WrongAnimal const & src);
		std::string	getType() const;
		void	makeSound() const;
	protected:
		std::string	_type;
};

#endif

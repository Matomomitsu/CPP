/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:52:34 by mtomomit          #+#    #+#             */
/*   Updated: 2023/04/24 17:03:14 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>

class	Zombie{
	public:
		Zombie(void);
		Zombie(std::string name);
		virtual ~Zombie(void);
		Zombie & operator=(Zombie const & rhs);
		Zombie(Zombie const & src);
		void	announce(void);
		std::string	getName() const;
		void	setName(std::string name);
	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif

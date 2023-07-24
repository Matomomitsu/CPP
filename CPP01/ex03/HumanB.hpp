/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:27:34 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

# include "Weapon.hpp"
# include <iostream>

class	HumanB{
	public:
		HumanB(std::string name);
		virtual ~HumanB(void);
		std::string	getName() const;
		void	setName(std::string type);
		void	setWeapon(Weapon &weapon);
		void	attack() const;
	private:
		Weapon*		_weapon;
		std::string	_name;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:48:55 by mtomomit          #+#    #+#             */
/*   Updated: 2023/04/25 13:13:47 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

# include <iostream>

class	Weapon{
	public:
		Weapon(std::string type);
		virtual ~Weapon(void);
		Weapon & operator=(Weapon const & rhs);
		Weapon(Weapon const & src);
		std::string	const &getType() const;
		void	setType(std::string type);
	private:
		std::string	_type;
};

#endif

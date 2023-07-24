/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:18:14 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap{
	public:
		DiamondTrap(void);
		virtual ~DiamondTrap(void);
		DiamondTrap & operator=(DiamondTrap const & rhs);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap(std::string name);
		void	whoAmI();
	private:
		std::string	_name;
};

#endif

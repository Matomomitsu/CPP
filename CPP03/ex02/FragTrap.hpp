/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:06:41 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		virtual ~FragTrap(void);
		FragTrap & operator=(FragTrap const & rhs);
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		void	highFivesGuys(void);
	private:

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:50:43 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/02 12:08:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
	public:
		Fixed(void);
		virtual ~Fixed(void);
		Fixed & operator=(Fixed const & rhs);
		Fixed(Fixed const & src);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int	_rawBits;
		static const int _fractionalBits;
};

#endif

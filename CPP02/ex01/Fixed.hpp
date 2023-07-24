/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:15:04 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/03 10:29:34 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
	public:
		Fixed(void);
		virtual ~Fixed(void);
		Fixed & operator=(Fixed const & rhs);
		Fixed(Fixed const & src);
		Fixed(int const raw);
		Fixed(float const raw);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
	private:
		int	_rawBits;
		static const int _fractionalBits;
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixedPoint);

#endif

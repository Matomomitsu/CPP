/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:37:57 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/04 00:41:36 by mtomomit         ###   ########.fr       */
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
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		static Fixed &	min(Fixed &fixedPoint1, Fixed &fixedPoint2);
		static Fixed &	max(Fixed &fixedPoint1, Fixed &fixedPoint2);
		static const Fixed &	min(Fixed const &fixedPoint1, Fixed const &fixedPoint2);
		static const Fixed &	max(Fixed const &fixedPoint1, Fixed const &fixedPoint2);
	private:
		int	_rawBits;
		static const int _fractionalBits;
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixedPoint);

#endif

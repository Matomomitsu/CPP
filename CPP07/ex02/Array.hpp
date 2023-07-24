/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:18:11 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:47:44 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		virtual ~Array(void);
		Array & operator=(Array const & rhs);
		Array(Array const & src);
		unsigned int	size() const;
		class IndexOutOfBounds : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		T &operator[](unsigned int index) const;
	private:
		T *_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:32:48 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/26 14:18:32 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, size_t const size, void (*f)(T const &)){
	if (!array)
		return ;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T> void iter(T *array, size_t const size, void (*f)(T &)){
	if (!array)
		return ;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:09:46 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:46:59 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void	swap(T &x, T &y){
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T> T const &	max(T const &x, T const &y){
	return ((x > y) ? x : y);
}

template <typename T> T	const &	min(T const &x, T const &y){
	return ((x < y) ? x : y);
}

#endif

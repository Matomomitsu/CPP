/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:25:51 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 19:10:10 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class	ValueNotFoundException : public std::exception{
	virtual const char *what() const throw(){
		return ("Value not found");
	}
};

template <typename T> typename T::iterator	easyfind(T &container, int value){
	typename T::iterator occurence;

	occurence = std::find(container.begin(), container.end(), value);
	if (occurence == container.end())
		throw ValueNotFoundException();
	return (occurence);
}

#endif

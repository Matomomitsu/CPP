/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:00:17 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : number(0), string("test"){
}

Data::~Data(void){
}

Data & Data::operator=(Data const & rhs){
	if(this != &rhs){
		number = rhs.number;
		string = rhs.string;
	}
	return(*this);
}

Data::Data(Data const & src){
	*this = src;
	return ;
}

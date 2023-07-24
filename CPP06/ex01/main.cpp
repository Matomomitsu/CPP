/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:03:40 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/06 18:47:27 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
	Data	data;
	uintptr_t	pointer;

	data.number = 1;
	data.string = "It's me";
	std::cout << "Data string: " << data.string << "\nData number: " << data.number << std::endl;
	pointer = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << pointer << std::endl;
	std::cout << "CopyData string: " << Serializer::deserialize(pointer)->string << "\nCopyData number: " << Serializer::deserialize(pointer)->number << std::endl;
}

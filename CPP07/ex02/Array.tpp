/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:56:56 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/20 20:36:47 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T> Array<T>::Array(void) : _array(new T[0]), _size(0){
}

template <typename T> Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){
}

template <typename T> Array<T>::~Array(void){
	if (this->_array)
		delete[] this->_array;
}

template <typename T> Array<T> & Array<T>::operator=(Array const & rhs){
	if(this != &rhs){
		if (this->_array)
			delete[] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
		}
	return (*this);
}

template <typename T> Array<T>::Array(Array const & src) : _array(NULL), _size(0){
	*this = src;
	return ;
}

template <typename T> unsigned int	Array<T>::size() const{
	return (this->_size);
}

template <typename T> const char* Array<T>::IndexOutOfBounds::what() const throw()
{
	return("Index is out of bounds");
}

template <typename T> T &Array<T>::operator[](unsigned int index) const{
	if (index >= this->_size)
		throw Array::IndexOutOfBounds();
	return (this->_array[index]);
}

#endif

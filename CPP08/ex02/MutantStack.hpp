/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:07:58 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/21 16:36:21 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iostream>

template <typename T> class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		virtual ~MutantStack(void);
		MutantStack & operator=(MutantStack const & rhs);
		MutantStack(MutantStack const & src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

template <typename T> MutantStack<T>::MutantStack(void){
}

template <typename T> MutantStack<T>::~MutantStack(void){
}

template <typename T> MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs){
	if(this != &rhs){
		std::stack<T>::operator=(rhs);
	}
	return(*this);
}

template <typename T> MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src){
	*this = src;
	return ;
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end(){
	return (this->c.end());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
	return (this->c.rbegin());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){
	return (this->c.rend());
}

#endif

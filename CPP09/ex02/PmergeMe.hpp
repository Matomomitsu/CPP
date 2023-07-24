/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:13:43 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/22 18:06:11 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sys/time.h>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe(void);
		virtual ~PmergeMe(void);
		PmergeMe & operator=(PmergeMe const & rhs);
		PmergeMe(PmergeMe const & src);

		void	orderInput(char **input);
	private:
		bool	_verifyInput(char *input);
		std::vector<int>	_vector;
		std::list<int>		_list;
};

void	vectorInsertionSort(std::vector<int> &vec);
void	vectorMergeSort(std::vector<int> &result, std::vector<int> &left, std::vector<int> &right);
void	vectorMergeInsertionSort(std::vector<int> &vec);
void	listInsertionSort(std::list<int> &list);
void	listMergeSort(std::list<int> &result, std::list<int> &left, std::list<int> &right);
void	listMergeInsertionSort(std::list<int> &list);

#endif

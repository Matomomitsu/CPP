/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:13:30 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/22 21:56:16 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){
}

PmergeMe::~PmergeMe(void){
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs){
	if(this != &rhs){
	}
	return(*this);
}

PmergeMe::PmergeMe(PmergeMe const & src){
	*this = src;
	return ;
}

bool	PmergeMe::_verifyInput(char *input){
	size_t	i;

	i = 0;
	if (input[i] == '+')
		i++;
	while (input[i]){
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
			return (false);
	}
	float temp = atof(input);
	if (temp > 2147483647.0f)
		return(false);
	return (true);
}

void PmergeMe::orderInput(char **input){
	size_t	i;

	i = 1;
	while (input[i]){
		if (!_verifyInput(input[i])){
			std::cerr << "Error" << std::endl;
			return ;
		}
		int num = atoi(input[i]);
		this->_vector.push_back(num);
		this->_list.push_back(num);
		i++;
	}
	i = 1;
	std::cout << "Before: ";
	while (input[i]){
		std::cout << input[i] << " ";
		i++;
	}
	{
		std::cout << std::endl;
		std::clock_t	start = std::clock();
		vectorMergeInsertionSort(this->_vector);
		std::clock_t	end = std::clock();
		double duration = static_cast<double>((end - start) * 1000 / CLOCKS_PER_SEC);
		std::cout << "After: ";
		for(std::vector<int>::iterator	it = this->_vector.begin(); it != this->_vector.end(); it++){
		std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << i - 1 << " elements with std::vector : " << duration << "ms" << std::endl;
	}
	{
		std::clock_t	start = std::clock();
		listMergeInsertionSort(this->_list);
		std::clock_t	end = std::clock();
		double duration = static_cast<double>((end - start) * 1000 / CLOCKS_PER_SEC);
		std::cout << "Time to process a range of " << i - 1 << " elements with std::list : " << duration << "ms" << std::endl;
	}
}

void	vectorInsertionSort(std::vector<int> &vec){
	for (size_t	i = 1; i < vec.size(); i++){
		int key = vec[i];
		size_t	o = i - 1;
		while (o < vec.size() && vec[o] > key){
			vec[o + 1] = vec[o];
			o--;
		}
		vec[o + 1] = key;
	}
}

void	vectorMergeSort(std::vector<int> &result, std::vector<int> &left, std::vector<int> &right){
	result.reserve(left.size() + right.size());
	std::vector<int>::iterator	leftIt = left.begin();
	std::vector<int>::iterator	rightIt = right.begin();
	while (leftIt != left.end() && rightIt != right.end()){
		std::vector<int>::iterator lower = std::lower_bound(leftIt, left.end(), *rightIt);
		result.insert(result.end(), leftIt, lower);
		result.push_back(*rightIt);
		leftIt = lower;
		rightIt++;
	}
	result.insert(result.end(), leftIt, left.end());
	result.insert(result.end(), rightIt, right.end());
}

void	vectorMergeInsertionSort(std::vector<int> &vec){
	if (vec.size() <= 1)
		return ;
	else if (vec.size() <= 2){
		vectorInsertionSort(vec);
		return ;
	}
	size_t	half = vec.size() / 2;
	std::vector<int>	left(vec.begin(), vec.begin() + half);
	std::vector<int>	right(vec.begin() + half, vec.end());
	vectorMergeInsertionSort(left);
	vectorMergeInsertionSort(right);
	vec.clear();
	vectorMergeSort(vec, left, right);
}

void	listInsertionSort(std::list<int> &list){
	std::list<int>::iterator it = list.begin();
	it++;
	while (it != list.end()){
		int key = *it;
		std::list<int>::iterator i = it;
		i--;
		std::list<int>::iterator nextIt = it;
		++nextIt;
		while (i != list.end() && *i > key){
			std::iter_swap(i, it);
			if (i != list.begin()){
				i--;
				it--;
			}
			else
				break ;
		}
		it = nextIt;
	}
}

void	listMergeSort(std::list<int> &result, std::list<int> &left, std::list<int> &right){
	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end()){
		std::list<int>::iterator lower = std::lower_bound(leftIt, left.end(), *rightIt);
		result.insert(result.end(), leftIt, lower);
		result.push_back(*rightIt);
		leftIt = lower;
		rightIt++;
	}
	result.insert(result.end(), leftIt, left.end());
	result.insert(result.end(), rightIt, right.end());
}

void	listMergeInsertionSort(std::list<int> &list){
	if (list.size() <= 1)
		return ;
	else if (list.size() <= 40){
		listInsertionSort(list);
		return ;
	}
	size_t	half = list.size() / 2;
	std::list<int>::iterator	halfIt = list.begin();
	for(size_t	i = 0; i < half; i++)
		halfIt++;
	std::list<int>	left(list.begin(), halfIt);
	std::list<int>	right(halfIt, list.end());
	listMergeInsertionSort(left);
	listMergeInsertionSort(right);
	list.clear();
	listMergeSort(list, left, right);
}

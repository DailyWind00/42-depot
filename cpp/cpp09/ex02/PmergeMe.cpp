/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/17 15:43:35 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Canonical Form :
PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe( const PmergeMe &toCopy ) {
	*this = toCopy;
}

PmergeMe & PmergeMe::operator=( const PmergeMe &toCopy ) {
	(void)toCopy;
	return *this;
}

PmergeMe::~PmergeMe() {
}
// ---



// Static Functions :
static std::deque<size_t> DequeMergeInsertionSort(std::deque<size_t> list) {
	
	return list;
}

static std::vector<size_t> VectorMergeInsertionSort(std::vector<size_t> list) {
	
	return list;
}
// ---



// Public Functions :
std::deque<size_t> PmergeMe::ConvertDeque(char **args) {
	std::deque<size_t> list;
	for (int i = 0; args[i]; i++) {
		std::stringstream ss(args[i]);
		size_t num;
		ss >> num;
		if (ss.fail()) {
			throw std::invalid_argument("Invalid argument");
		}
		list.push_back(num);
	}
	return list;
}

std::vector<size_t> PmergeMe::ConvertVector(char **args) {
	std::vector<size_t> list;
	for (int i = 0; args[i]; i++) {
		std::stringstream ss(args[i]);
		size_t num;
		ss >> num;
		if (ss.fail()) {
			throw std::invalid_argument("Invalid argument");
		}
		list.push_back(num);
	}
	return list;
}

const std::deque<size_t> PmergeMe::DequeMergeInsert(std::deque<size_t> &list, double &time) {
	std::clock_t start = std::clock();
	list = DequeMergeInsertionSort(list);
	std::clock_t end = std::clock();
	time = (end - start) * 1000000 / CLOCKS_PER_SEC;
	return list;
}

const std::vector<size_t> PmergeMe::VectorMergeInsert(std::vector<size_t> &list, double &time) {
	std::clock_t start = std::clock();
	list = VectorMergeInsertionSort(list);
	std::clock_t end = std::clock();
	time = (end - start) * 1000000 / CLOCKS_PER_SEC;
	return list;
}

void PmergeMe::PrintDeque(const std::deque<size_t> &list) {
	bool i = true;
	for (std::deque<size_t>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if (i) {
			std::cout << BWhite;
			i = false;
		} else {
			std::cout << BGray;
			i = true;
		}
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::PrintVector(const std::vector<size_t> &list) {
	bool i = true;
	for (std::vector<size_t>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if (i) {
			std::cout << BWhite;
			i = false;
		} else {
			std::cout << BGray;
			i = true;
		}
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
// ---
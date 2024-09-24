/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/24 12:08:36 by mgallais         ###   ########.fr       */
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
static std::deque<size_t> DequeMergeInsertionSort(std::deque<size_t> list, bool recursive = true) {
	std::deque<size_t> sorted_list;
	pairDeq pairs; // Deque container of pairs
	bool insert = true;
	
	if (list.size() % 2) { // Odd number of elements handling
		sorted_list.push_back(list.back());
		list.pop_back();
	}
	for (std::deque<size_t>::iterator it = list.begin(); it != list.end(); it++, insert = !insert) { // pairing
		if (insert) {
			std::pair<size_t, size_t> pair;
			pair.first = *it;
			pairs.push_back(pair);
		} else {
			pairs.back().second = *it;
			if (pairs.back().first > pairs.back().second) // pair(lowest, highest)
				std::swap(pairs.back().first, pairs.back().second);
			// std::cout << "pair : " << pairs.back().first << " " << pairs.back().second << std::endl;
		}
	}
	if (recursive) { // Redo the merge-insertion sort with the lowest of each pairs, then again with the highest
		std::deque<size_t> lowest_list, highest_list;
		for (pairDeq::iterator it = pairs.begin(); it != pairs.end(); it++) {
			lowest_list.push_back(it->first);
			highest_list.push_back(it->second);
		}
		pairs.clear();
		lowest_list = DequeMergeInsertionSort(lowest_list, false);
		highest_list = DequeMergeInsertionSort(highest_list, false);
		
		// wikipedia
		// sorted_list = binary_search();

		return sorted_list;
	}

	for (pairDeq::iterator it = pairs.begin(); it != pairs.end(); it++) { // If not recursive, pairs should be sorted
		sorted_list.push_back(it->first);
		sorted_list.push_back(it->second);
	}
	pairs.clear();
	return sorted_list;
}

// static std::vector<size_t> VectorMergeInsertionSort(std::vector<size_t> list, bool recursive = true) {
// 	// todo
// 	return sorted_list;
// }
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
	// list = VectorMergeInsertionSort(list, true);
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
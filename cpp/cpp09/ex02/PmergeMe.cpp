/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/25 10:48:31 by mgallais         ###   ########.fr       */
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
static bool DequeIsSorted(std::deque<size_t>& list) {
	if (list.size() <= 1) {
		return true;
	}
	std::deque<size_t>::iterator it = list.begin();
	size_t prev = *it;
	++it;
	while (it != list.end()) {
		if (*it < prev) {
			return false;
		}
		prev = *it;
		++it;
	}
	return true;
}

// static bool VectorIsSorted(std::vector<size_t>& list) {
// 	if (list.size() <= 1) {
// 		return true;
// 	}
// 	std::vector<size_t>::iterator it = list.begin();
// 	size_t prev = *it;
// 	++it;
// 	while (it != list.end()) {
// 		if (*it < prev) {
// 			return false;
// 		}
// 		prev = *it;
// 		++it;
// 	}
// 	return true;
// }

static std::deque<size_t> DequeMergeInsertionSort(std::deque<size_t> list) {
	if (DequeIsSorted(list))
		return list;

	std::deque<size_t> sorted_list;
	pairDeq pairs; // Deque container of pairs
	bool odd = (bool)(list.size() % 2);
	bool insert = true;

	if (DEBUG)
		std::cout << std::endl;

	if (odd) { // Odd number of elements handling
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
			if (pairs.back().first < pairs.back().second) // pair(highest, lowest)
				std::swap(pairs.back().first, pairs.back().second);
		}
	}

	std::deque<size_t> highest_list, lowest_list;
	for (pairDeq::iterator it = pairs.begin(); it != pairs.end(); it++) {
        highest_list.push_back(it->first);
		lowest_list.push_back(it->second);
	}
	if (DEBUG)
		PmergeMe::PrintDeque(highest_list);

 	sorted_list = DequeMergeInsertionSort(highest_list);

	if (DEBUG)
		PmergeMe::PrintDeque(sorted_list);

	// jacobstall

	for (pairDeq::iterator it = pairs.begin(); it != pairs.end(); it++) {  // Binary sort
		long left = 0;
		long right = sorted_list.size();
		bool doublon = false;

        while (left < right) {
			long mid = (left + right) / 2; // automatic floor
			std::cout << mid << std::endl;

			if (sorted_list[mid] < it->second)
				left = mid + 1;
			else if (sorted_list[mid] > it->second)
				right = mid - 1;
			else {
				doublon = true;
				break ;
			}
		}
		if (!doublon) // Doublon are ignored
			sorted_list.insert(sorted_list.begin() += right, it->second);
		if (DEBUG)
			PmergeMe::PrintDeque(sorted_list);
	}

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

const std::deque<size_t> PmergeMe::DequeMergeInsert(std::deque<size_t> list, double &time) {
	std::clock_t start = std::clock();
	list = DequeMergeInsertionSort(list);
	std::clock_t end = std::clock();
	time = (end - start) * 1000000 / CLOCKS_PER_SEC;
	return list;
}

const std::vector<size_t> PmergeMe::VectorMergeInsert(std::vector<size_t> list, double &time) {
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:06 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/25 15:49:01 by mgallais         ###   ########.fr       */
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
bool PmergeMe::DequeIsSorted(std::deque<size_t>& list) {
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

bool PmergeMe::VectorIsSorted(std::vector<size_t>& list) {
	if (list.size() <= 1) {
		return true;
	}
	std::vector<size_t>::iterator it = list.begin();
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

std::deque<size_t> PmergeMe::DequeSort(std::deque<size_t> list) {
	if (DequeIsSorted(list))
		return list;

	std::deque<size_t> sorted_list;
	
	sorted_list.push_front(list.front());
	list.pop_front();

	for (std::deque<size_t>::iterator it = list.begin(); it != list.end(); it++) { // Binary sort
		long left = 0;
		long right = sorted_list.size() - 1;
		bool doublon = false;
		
		while (left <= right) {
			long mid = (left + right) / 2; // floor
					if (sorted_list[mid] == *it) {
				doublon = true;
				break ;
			}
			else if (sorted_list[mid] < *it)
				left = mid + 1;
			else if (sorted_list[mid] > *it)
				right = mid - 1;
		}
	
		if (!doublon) { // Doublon are ignored
			std::deque<size_t>::iterator insert_it = sorted_list.begin();
			for (long i = 0; i < left; i++) {
				insert_it++;
			}
			sorted_list.insert(insert_it, *it);
		}
	}

	return sorted_list;
}

std::vector<size_t> PmergeMe::VectorSort(std::vector<size_t> list) {
	if (VectorIsSorted(list))
		return list;

	std::vector<size_t> sorted_list;

	sorted_list.push_back(list.front());
	list.erase(list.begin());

	for (std::vector<size_t>::iterator it = list.begin(); it != list.end(); it++) { // Binary sort
		long left = 0;
		long right = sorted_list.size() - 1;
		bool doublon = false;

		while (left <= right) {
			long mid = (left + right) / 2; // floor

			if (sorted_list[mid] == *it) {
				doublon = true;
				break;
			}
			else if (sorted_list[mid] < *it)
				left = mid + 1;
			else if (sorted_list[mid] > *it)
				right = mid - 1;
		}

		if (!doublon) { // Doublon are ignored
			std::vector<size_t>::iterator insert_it = sorted_list.begin();
			for (long i = 0; i < left; i++) {
				insert_it++;
			}
			sorted_list.insert(insert_it, *it);
		}
	}

	return sorted_list;
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

const std::deque<size_t> PmergeMe::DequeMergeInsert(std::deque<size_t> list, double &time) {
	std::clock_t start = std::clock();
	list = DequeSort(list);
	std::clock_t end = std::clock();
	time = (end - start) * 1000000 / CLOCKS_PER_SEC;
	return list;
}

const std::vector<size_t> PmergeMe::VectorMergeInsert(std::vector<size_t> list, double &time) {
	std::clock_t start = std::clock();
	list = VectorSort(list);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/17 15:16:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if ( argc < 2 ) {
		std::cerr << "Correct syntax : ./PmergeMe <positives numbers>\n";
		return -1;
	}

	try
	{
		double DequeTime = 0;
		double VectorTime = 0;
		argv++;

		std::deque<size_t> deque = PmergeMe::ConvertDeque(argv);
		std::vector<size_t> vector = PmergeMe::ConvertVector(argv);

		std::deque<size_t> dequeSorted = PmergeMe::DequeMergeInsert(deque, DequeTime);
		std::vector<size_t> vectorSorted = PmergeMe::VectorMergeInsert(vector, VectorTime);

		std::cout << BWhite << "Before : "; PmergeMe::PrintDeque(deque); std::cout << std::endl;
		std::cout << BWhite << "After : "; PmergeMe::PrintDeque(dequeSorted); std::cout << std::endl;
		std::cout << BWhite << "Time to process a range of " << dequeSorted.size() << " elements with deque : " << DequeTime << " us\n";
		std::cout << BWhite << "Time to process a range of " << vectorSorted.size() << " elements with vector : " << VectorTime << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << '\n';
	}
}
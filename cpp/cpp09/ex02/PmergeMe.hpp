/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:34:03 by mgallais          #+#    #+#             */
/*   Updated: 2024/09/24 11:51:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>
# include <deque>
# include <vector>
# include <ctime>

# define BWhite	"\033[1;37m"
# define BGray	"\033[1;38;5;250m"

# ifndef DEBUG
#  define DEBUG 1
# endif

typedef std::vector<std::pair<size_t, size_t> > pairVec;
typedef std::deque<std::pair<size_t, size_t> > pairDeq;

class PmergeMe {
	public :
		/// Canonical Form :
		PmergeMe();
		PmergeMe( const PmergeMe &toCopy );
		PmergeMe & operator=( const PmergeMe &toCopy );
		~PmergeMe();
		
		/// Public Functions :
		static std::deque<size_t>	ConvertDeque(char **args);
		static std::vector<size_t>	ConvertVector(char **args);
		
		static const std::deque<size_t>		DequeMergeInsert(std::deque<size_t> list, double &time);
		static const std::vector<size_t>	VectorMergeInsert(std::vector<size_t> list, double &time);
		
		static void PrintDeque(const std::deque<size_t> &list);
		static void PrintVector(const std::vector<size_t> &list);

		static bool DequeIsSorted(std::deque<size_t>& list);
		static bool VectorIsSorted(std::vector<size_t>& list);

		static std::deque<size_t> DequeSort(std::deque<size_t> list);
		static std::vector<size_t> VectorSort(std::vector<size_t> list);
};

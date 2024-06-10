/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dailywind <dailywind@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/04 11:31:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define BRed "\033[1;31m" 
#define Color_Off "\033[0m"

bool testBsp() {
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(0), Fixed(12.5f));
    Point pointInside(Fixed(4.5f), Fixed(4.5f));
    Point pointOnEdge(Fixed(0), Fixed(5));
    Point pointOnCorner(Fixed(0), Fixed(12.5f));
    Point pointOutside(Fixed(15), Fixed(15));

	std::cout << "Point is outside a triangle if : Vectors < 0 || VectorX + VectorY > 1\n\n"; 

    if (!bsp(a, b, c, pointInside)) {
        std::cout << "Test failed: pointInside should be inside the triangle\n";
        return false;
    }

    if (!bsp(a, b, c, pointOnEdge)) {
        std::cout << "Test failed: pointOnEdge should be inside the triangle\n";
        return false;
    }

    if (!bsp(a, b, c, pointOnCorner)) {
        std::cout << "Test failed: pointOnCorner should be inside the triangle\n";
        return false;
    }

    if (bsp(a, b, c, pointOutside)) {
        std::cout << "Test failed: pointOutside should be outside the triangle\n";
        return false;
    }

    return true;
}

int main() {
    if (testBsp()) {
        std::cout << "All tests passed!\n";
    } else {
        std::cout << "Some tests failed.\n";
    }

    return 0;
}

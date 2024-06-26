/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/26 09:28:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

    Span sp = Span(5);

    // Crash if no numbers in Span
    try
    {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    // ---

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    // Crash if too many numbers in Span
    try
    {
        sp.addNumber(42);
    }
    catch ( std::exception &e )
    {
        std::cout << e.what() << std::endl;
    }
    // ---

    std::cout << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    sp.clearSpan();
    int nums[] = {1, 2, 3, 4, 5};
    sp.addNumber(nums, 5);

    std::cout << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    return 0;
}
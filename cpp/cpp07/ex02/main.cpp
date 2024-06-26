/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 14:55:44 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp" // This is the only way to compile this code because of the template

int main() {
    // Test case 1: Creating an array of integers
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 1;
    }
    std::cout << "Integer Array: ";
    for (size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test case 2: Creating an array of characters
    Array<char> charArray(3);
    charArray[0] = 'A';
    charArray[1] = 'B';
    charArray[2] = 'C';
    std::cout << "Character Array: ";
    for (size_t i = 0; i < charArray.size(); i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    // Test case 3: Creating an empty array
    Array<double> doubleArray;
    std::cout << "Double Array size: " << doubleArray.size() << std::endl;

    return 0;
}
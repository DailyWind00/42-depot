/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:56:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/25 15:48:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int main() {

    std::vector<int> v;

    // Fill the vector with 42 elements from 10 to 420
    for (int i = 1; i <= 42; i++)
        v.push_back(i * 10);

    // Try to find the value 110 in the vector
    try
    {
        std::vector<int>::iterator it = easyfind(v, 110);
        std::cout << "Value found at index " << it - v.begin() << std::endl;
    }
    catch ( std::exception &e )
    {
        std::cout << "Value not found" << std::endl;
    }

    // Try to find the value 420 in the vector
    try
    {
        std::vector<int>::iterator it = easyfind(v, 420);
        std::cout << "Value found at index " << it - v.begin() << std::endl;
    }
    catch ( std::exception &e )
    {
        std::cout << "Value not found" << std::endl;
    }

    // Try to find the value 1000 in the vector (error)
    try
    {
        std::vector<int>::iterator it = easyfind(v, 1000);
        std::cout << "Value found at index " << it - v.begin() << std::endl;
    }
    catch ( std::exception &e )
    {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
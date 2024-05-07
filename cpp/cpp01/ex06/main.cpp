/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:38:40 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/07 12:12:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int main(int argc, char **argv) {
    Harl Karen;
    if (argc != 2){
        std::cout << "Correct syntax : ./harlfilter <complain>" << std::endl;
        return EXIT_FAILURE;
    }
    Karen.complain(argv[1]);

    return EXIT_SUCCESS;
}
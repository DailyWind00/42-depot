/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:38:40 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/07 11:48:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl Karen;
    Karen.complain("DEBUG");
    Karen.complain("INFO");
    Karen.complain("WARNING");
    Karen.complain("ERROR");
    Karen.complain("INVALID"); // Test with an invalid level

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:25:27 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 23:25:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type){}

Weapon::~Weapon(){}

const std::string&	Weapon::getType() const { return this->type; }
void	Weapon::setType(const std::string& type) { this->type = type; }
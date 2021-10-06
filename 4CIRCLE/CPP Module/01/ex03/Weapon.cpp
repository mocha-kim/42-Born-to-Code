/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:39:29 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 21:09:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) { this->type = type; }

Weapon::~Weapon() {}

const std::string&	Weapon::getType() { return (this->type); }

void	Weapon::setType(std::string type) { this->type = type; }
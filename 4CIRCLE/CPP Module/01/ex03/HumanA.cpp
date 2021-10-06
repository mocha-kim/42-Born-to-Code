/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:14:41 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 01:38:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	if (name == "")
	{
		std::cout << "[Warning] HumanA create failed: HumanA must have name" << std::endl;
		throw ;
	}
	if (weapon.getType() == "")
	{
		std::cout << "[Warning] HumanA create failed: New Weapon must have type." << std::endl;
		throw ;
	}
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA() {}

void	HumanA::setWeapon(Weapon &weapon)
{
	if (weapon.getType() == "")
	{
		std::cout << "[Warning] setWeapon failed: New Weapon must have type." << std::endl;
		return ;
	}
	this->weapon = &weapon;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
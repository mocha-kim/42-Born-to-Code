/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:10:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 21:49:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	if (name == "")
	{
		std::cout << "[Warning] HumanB create failed: HumanB must have name" << std::endl;
		return ;
	}
	this->name = name;
	this->weapon = nullptr;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	if (weapon.getType() == "")
	{
		std::cout << "[Warning] setWeapon failed: New Weapon must have type." << std::endl;
		return ;
	}
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (!this->weapon || this->weapon->getType() == "")
	{
		std::cout << this->name << " bravely attacked with his bare hands" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
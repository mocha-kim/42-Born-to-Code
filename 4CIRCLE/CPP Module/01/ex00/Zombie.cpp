/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:11:55 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 20:07:15 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	Zombie::_prefix();
	std::cout << "A living dead died again." << std::endl;
}

void	Zombie::_prefix()
{
	std::cout << "<" << this->name << "> ";
}

void	Zombie::announce()
{
	Zombie::_prefix();
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:51:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 17:12:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "";
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = copy.name;
	this->hit = copy.hit;
	this->energy = copy.energy;
	this->damage = copy.damage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &op)
{
	this->name = op.name;
	this->hit = op.hit;
	this->energy = op.energy;
	this->damage = op.damage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->energy -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " be repaired " << amount << " points of energy!" << std::endl;
	this->energy += amount;
}
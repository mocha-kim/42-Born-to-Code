/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:51:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 18:33:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "";
	this->hitpoints = 10;
	this->energy = 10;
	this->damage = 0;
	this->_prefix();
	std::cout << "\bdefault constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitpoints = 10;
	this->energy = 10;
	this->damage = 0;
	this->_prefix();
	std::cout << "name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->damage = copy.damage;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

void	ClapTrap::_prefix()
{
	std::cout << "ClapTrap " << this->name << " ";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &op)
{
	this->_prefix();
	std::cout << "assignation operator called" << std::endl;
	this->name = op.name;
	this->hitpoints = op.hitpoints;
	this->energy = op.energy;
	this->damage = op.damage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	this->_prefix();
	std::cout << "attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_prefix();
	std::cout << "takes " << amount << " points of damage!" << std::endl;
	this->energy -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_prefix();
	std::cout << "be repaired " << amount << " points of energy!" << std::endl;
	this->energy += amount;
}

void	ClapTrap::debug()
{
	this->_prefix();
	std::cout << "(" << this->hitpoints << ", " << this->energy << ", " << this->damage << ")" << std::endl;
}
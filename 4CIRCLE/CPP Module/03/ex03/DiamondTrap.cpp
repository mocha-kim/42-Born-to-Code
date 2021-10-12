/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:31:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 20:43:40 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "";
	this->hitpoints = this->FragTrap::hitpoints;
	this->energy = this->ScavTrap::energy;
	this->damage = this->FragTrap::damage;
	this->_prefix();
	std::cout << "\bdefault constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hitpoints = this->FragTrap::hitpoints;
	this->energy = this->ScavTrap::energy;
	this->damage = this->FragTrap::damage;
	this->_prefix();
	std::cout << "name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy):ClapTrap(copy.name), FragTrap(copy.name), ScavTrap(copy.name)
{
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->damage = copy.damage;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

void	DiamondTrap::_prefix()
{
	std::cout << "DiamondTrap " << this->name << " ";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &op)
{
	this->_prefix();
	std::cout << "assignation operator called" << std::endl;
	this->name = op.name;
	this->hitpoints = op.hitpoints;
	this->energy = op.energy;
	this->damage = op.damage;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	this->_prefix();
	std::cout << "has also clapTrap name " << this->ClapTrap::name << std::endl;
}

void	DiamondTrap::debug()
{
	this->_prefix();
	std::cout << "(" << this->hitpoints << ", " << this->energy << ", " << this->damage << ")" << std::endl;
}
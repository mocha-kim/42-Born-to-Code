/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:23:28 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 20:14:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "";
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
	this->_prefix();
	std::cout << "\bdefault constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
	this->_prefix();
	std::cout << "name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy):ClapTrap(copy.name)
{
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->damage = copy.damage;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

void	ScavTrap::_prefix()
{
	std::cout << "ScavTrap " << this->name << " ";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &op)
{
	this->_prefix();
	std::cout << "assignation operator called" << std::endl;
	this->name = op.name;
	this->hitpoints = op.hitpoints;
	this->energy = op.energy;
	this->damage = op.damage;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	this->_prefix();
	std::cout << "attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	this->_prefix();
	std::cout << "have entered in Gate keeper mode" << std::endl;
}
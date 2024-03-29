/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:53:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 20:42:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "";
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
	this->_prefix();
	std::cout << "\bdefault constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
	this->_prefix();
	std::cout << "name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy.name)
{
	this->hitpoints = copy.hitpoints;
	this->energy = copy.energy;
	this->damage = copy.damage;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

void	FragTrap::_prefix()
{
	std::cout << "FragTrap " << this->name << " ";
}

FragTrap	&FragTrap::operator=(const FragTrap &op)
{
	this->_prefix();
	std::cout << "assignation operator called" << std::endl;
	this->name = op.name;
	this->hitpoints = op.hitpoints;
	this->energy = op.energy;
	this->damage = op.damage;
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	this->_prefix();
	std::cout << "attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	this->_prefix();
	std::cout << "wants to give high fives" << std::endl;
}

void	FragTrap::debug()
{
	this->_prefix();
	std::cout << "(" << this->hitpoints << ", " << this->energy << ", " << this->damage << ")" << std::endl;
}
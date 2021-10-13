/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:48 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 22:16:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name)
{
	if (name == "")
		std::cout << "[Warning] name is empty string" << std::endl;
	this->name = name;
	this->equipped = 0;
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::Character(Character const &copy)
{
	this->name = copy.name;
	this->equipped = copy.equipped;
	for (int i = 0; i < this->equipped; i++)
		this->slots[i] = copy.slots[i]->clone();
	for (int i = this->equipped; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
}

Character &Character::operator=(Character const &op)
{
	this->name = op.name;
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
	this->equipped = op.equipped;
	for (int i = 0; i < this->equipped; i++)
		this->slots[i] = op.slots[i]->clone();
	for (int i = this->equipped; i < 4; i++)
		this->slots[i] = nullptr;
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (m == nullptr || this->equipped == 3)
	{
		std::cout << "[Warning] " << this->name << " cannot equip materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == m)
		{
			std::cout << "[Info] " << m->getType() << " is already equipped" << std::endl;
			return ;
		}
	}
	this->slots[this->equipped] = m;
	this->equipped++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equipped)
	{
		std::cout << "[Warning] idx is invailed" << std::endl;
		return ;
	}
	for (int i = idx; i < 3; i++)
	{
		this->slots[i] = this->slots[i + 1];
		this->slots[i + 1] = nullptr;
	}
	this->equipped--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->equipped)
	{
		std::cout << "[Warning] idx is invailed" << std::endl;
		return ;
	}
	this->slots[idx]->use(target);
}

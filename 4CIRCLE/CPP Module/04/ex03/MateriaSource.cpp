/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:54:55 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 22:25:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->num = 0;
	for (int i = 0; i < 4; i++)
		this->sources[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	this->num = copy.num;
	for (int i = 0; i < copy.num; i++)
		this->sources[i] = copy.sources[i]->clone();
	for (int i = copy.num; i < 4; i++)
		this->sources[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->sources[i];
}


MateriaSource &MateriaSource::operator=(MateriaSource const &op)
{
	for (int i = 0; i < 4; i++)
		delete this->sources[i];
	this->num = op.num;
	for (int i = 0; i < op.num; i++)
		this->sources[i] = op.sources[i]->clone();
	for (int i = op.num; i < 4; i++)
		this->sources[i] = nullptr;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (this->num == 4 || m == nullptr)
	{
		std::cout << "[Warning] Materia Source cannot learn materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->sources[i] == m)
		{
			std::cout << "[Info] " << m->getType() << " is already learned" << std::endl;
			return ;
		}
	}
	this->sources[this->num] = m;
	this->num++;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->num; i++)
	{
		if (this->sources[i]->getType() == type)
		{
			return (this->sources[i]->clone());
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:39:13 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 22:27:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &copy) : AMateria("cure")
{
	this->type = copy.type;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &op)
{
	this->type = op.type;
	return (*this);
}

AMateria	*Cure::clone() const
{
	Cure	*clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
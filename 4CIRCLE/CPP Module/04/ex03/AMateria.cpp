/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:02:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 16:53:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(AMateria const & copy)
{
	this->type = copy.type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const & op)
{
	this->type = op.type;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* do something on " << target.getName() << " *" << std::endl;
}
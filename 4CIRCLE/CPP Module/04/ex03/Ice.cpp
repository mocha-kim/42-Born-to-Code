/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:54:06 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 22:27:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &copy) : AMateria("ice")
{
	this->type = copy.type;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &op)
{
	this->type = op.type;
	return (*this);
}

AMateria	*Ice::clone() const
{
	Ice	*clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
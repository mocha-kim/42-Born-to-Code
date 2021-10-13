/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:53:21 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 18:04:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "";
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type)
{
	this->type = type;
	this->_prefix();
	std::cout << "type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &op)
{
	this->type = op.type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* Something mysterious sound of unknown animal *" << std::endl;
}

void	WrongAnimal::_prefix()
{
	std::cout << "WrongAnimal ";
}
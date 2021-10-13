/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:41:10 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 18:04:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Animal::Animal(const std::string type)
{
	this->type = type;
	this->_prefix();
	std::cout << "type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Animal::~Animal()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &op)
{
	this->type = op.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "* Something mysterious sound of unknown animal *" << std::endl;
}

void	Animal::_prefix()
{
	std::cout << "Animal ";
}
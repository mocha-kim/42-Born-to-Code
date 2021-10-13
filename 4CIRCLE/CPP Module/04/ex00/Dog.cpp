/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 01:54:55 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->type = copy.type;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Dog::~Dog()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &op)
{
	this->type = op.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "woof, woof!૮(•̀ᴥ•́)ა" << std::endl;
}

void	Dog::_prefix()
{
	std::cout << this->type << " ";
}
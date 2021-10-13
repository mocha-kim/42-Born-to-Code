/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:15:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	this->brain = new Brain();
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy):Animal("Dog")
{
	this->brain = new Brain(*copy.brain);
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Dog::Dog(const Brain &brain):Animal("Dog")
{
	this->brain = new Brain(brain);
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &op)
{
	this->type = op.type;
	this->brain = new Brain(*op.brain);
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

void	Dog::debug()
{
	this->_prefix();
	std::cout << "address: " << this << std::endl;
	this->brain->debug();
}
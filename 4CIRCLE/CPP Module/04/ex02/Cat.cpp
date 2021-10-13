/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:45:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	this->brain = new Brain();
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy):Animal("Cat")
{\
	this->brain = new Brain(*copy.brain);
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Cat::Cat(const Brain &brain):Animal("Cat")
{
	this->brain = new Brain(brain);
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &op)
{
	this->type = op.type;
	this->brain = new Brain(*op.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "meow meoooW(=ↀωↀ=)" << std::endl;
}

void	Cat::_prefix()
{
	std::cout << this->type << " ";
}

void	Cat::debug()
{
	this->_prefix();
	std::cout << "address: " << this << std::endl;
	this->brain->debug();
}
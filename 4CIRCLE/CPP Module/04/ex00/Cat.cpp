/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 16:27:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy):Animal("Cat")
{
	this->_prefix();
	this->type = copy.type;
	std::cout << "copy constructor called" << std::endl;
}

Cat::~Cat()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &op)
{
	this->type = op.type;
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
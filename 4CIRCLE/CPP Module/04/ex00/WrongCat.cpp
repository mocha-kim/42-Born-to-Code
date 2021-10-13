/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:56:04 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 17:56:36 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("Cat")
{
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	this->type = copy.type;
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &op)
{
	this->type = op.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "meow meoooW(=ↀωↀ=)" << std::endl;
}

void	WrongCat::_prefix()
{
	std::cout << this->type << " ";
}
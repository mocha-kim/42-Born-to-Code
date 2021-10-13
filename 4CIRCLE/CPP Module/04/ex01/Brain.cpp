/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:14:37 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:13:04 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	this->_prefix();
	std::cout << "default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	this->_prefix();
	std::cout << "copy constructor called" << std::endl;
}

Brain::~Brain()
{
	this->_prefix();
	std::cout << "destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &op)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = op.ideas[i];
	return (*this);
}

void	Brain::_prefix() const
{
	std::cout << "Brain ";
}

void	Brain::debug() const
{
	Brain::_prefix();
	std::cout << "address: " << this << std::endl;
}
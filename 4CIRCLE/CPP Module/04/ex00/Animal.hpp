/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:27:12 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 18:02:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	type;

	void	_prefix();

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	virtual	~Animal();

	Animal	&operator=(const Animal &op);

	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif
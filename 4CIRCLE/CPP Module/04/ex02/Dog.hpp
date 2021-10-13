/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:29 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:13:30 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;
	
	void	_prefix();
	
public:
	Dog();
	Dog(const Dog &copy);
	Dog(const Brain &brain);
	virtual ~Dog();

	Dog	&operator=(const Dog &op);
	
	void	makeSound() const;
	void	debug();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:53:24 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:13:26 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;
	
	void	_prefix();
	
public:
	Cat();
	Cat(const Cat &copy);
	Cat(const Brain &brain);
	virtual ~Cat();

	Cat	&operator=(const Cat &op);

	void	makeSound() const;
	void	debug();
};

#endif
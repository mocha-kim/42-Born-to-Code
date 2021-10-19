/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:19:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 16:44:58 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// Animal anim; // it must be error

	std::cout << "========== Test1: Cat ==========" << std::endl;
	Cat	*chaos = new Cat();
	std::cout << chaos->getType() << ": ";
	chaos->makeSound();
	delete chaos;
	std::cout << std::endl;

	std::cout << "========== Test2: Dog ==========" << std::endl;
	Dog	*puppy = new Dog();
	std::cout << puppy->getType() << ": ";
	puppy->makeSound();
	delete puppy;
	std::cout << std::endl;

	std::cout << "========== Test3: Copy =========" << std::endl;
	Brain	b;
	b.debug();
	Dog	basic = Dog(b);
	basic.debug();
	std::cout << "> before scope" << std::endl;
	{
		std::cout << "> start of scope" << std::endl;
		Dog tmp = basic;
		tmp.debug();
		std::cout << "> end of scope" << std::endl;
	}
	std::cout << "> after scope" << std::endl;
}
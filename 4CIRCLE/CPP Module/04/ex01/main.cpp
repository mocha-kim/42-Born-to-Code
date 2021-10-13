/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:05:52 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:18:37 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	Brain	brain;

	std::cout << "========== Test1: Cat ==========" << std::endl;
	Cat	*black = new Cat();
	Cat	*chaos = new Cat(brain);
	Cat *tuxedo = new Cat(*black);
	std::cout << std::endl;
	black->debug();
	chaos->debug();
	tuxedo->debug();
	std::cout << std::endl;
	delete black;
	delete chaos;
	delete tuxedo;
	std::cout << std::endl;

	std::cout << "========== Test2: Dog ==========" << std::endl;
	Dog	*puppy = new Dog();
	Dog *kkam = new Dog(brain);
	Dog *poodle = new Dog(*puppy);
	std::cout << std::endl;
	puppy->debug();
	kkam->debug();
	poodle->debug();
	std::cout << std::endl;
	delete puppy;
	delete kkam;
	delete poodle;
	std::cout << std::endl;

	std::cout << "========= Test3: scope =========" << std::endl;
	Dog	basic;
	basic.debug();
	std::cout << "> before scope" << std::endl;
	{
		std::cout << "> start of scope" << std::endl;
		Dog tmp = basic;
		tmp.debug();
		std::cout << "> end of scope" << std::endl;
	}
	std::cout << "> after scope" << std::endl;
	
	return (0);
}
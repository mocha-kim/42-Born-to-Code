/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:59:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 16:32:05 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "============= Test1: Right Animals =============" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << i->getType() << ": ";
	i->makeSound(); //will output the cat sound!
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	std::cout << "============= Test2: Wrong Animals =============" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	const WrongCat* l = new WrongCat();
	std::cout << k->getType() << ": ";
	k->makeSound();
	std::cout << l->getType() << ": ";
	l->makeSound();
	std::cout << meta2->getType() << ": ";
	meta2->makeSound();
	delete k;
	delete l;
	delete meta2;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:15 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 17:15:07 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* tmp;

	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete me;

	Character original = Character("original");
	tmp = src->createMateria("ice");
	original.equip(tmp);
	tmp = src->createMateria("cure");
	original.equip(tmp);
	Character copy = original;
	copy.unequip(0);
	copy.use(0, *bob);
	copy.use(1, *bob);
	original.use(0, *bob);
	original.use(1, *bob);

	delete bob;
	delete src;
	
	return 0;
}
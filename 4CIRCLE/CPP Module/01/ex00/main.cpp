/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:13:04 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 20:10:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "================== TEST1: newZombie ==================" << std::endl;
	std::cout << "> created zombies.. (name: Jack, Tom, Susan, Simpson)" << std::endl;
	Zombie *a = newZombie("Jack");
	Zombie *b = newZombie("Tom");
	Zombie *c = newZombie("Susan");
	Zombie *d = newZombie("Simpson");

	std::cout << "> zombies announce themselves.." << std::endl;
	a->announce();
	b->announce();
	c->announce();
	d->announce();

	std::cout << "> and kill zombies.." << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;

	std::cout << "================= TEST2: randomChump =================" << std::endl;
	std::cout << "> call chump zomebies.. (name: chump1, chump2, chump3)" << std::endl;
	randomChump("chump1");
	randomChump("chump2");
	randomChump("chump3");
}
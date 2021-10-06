/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:19:53 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 20:29:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies = zombieHorde(4, "zombie");

	std::cout << "========= TEST1 : 4 zombies named zombie =========" << std::endl;
	for (int i = 0; i < 4; i++)
		zombies[i].announce();
	delete [] zombies;

	std::cout << "======== TEST2 : 8 zombies named zozombie ========" << std::endl;
	zombies = zombieHorde(9, "zozombie");

	for (int i = 0; i < 9; i++)
		zombies[i].announce();
	delete [] zombies;
}
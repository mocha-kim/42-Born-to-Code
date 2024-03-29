/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:13:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 20:18:51 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].setName(name);

	return (zombieHorde);
}
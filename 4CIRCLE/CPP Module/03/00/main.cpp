/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:12:20 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 17:15:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	trapA = ClapTrap("trapA");
	ClapTrap	trapB("trapB");

	trapA.attack("Frog");
	trapA.takeDamage(4);
	trapB.takeDamage(2);
	trapB.attack("Frog");
	trapB.beRepaired(2);
	return (0);
}
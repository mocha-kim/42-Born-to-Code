/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:12:20 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 18:35:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	trapA = ClapTrap("trapA");
	ClapTrap	trapB("trapB");
	ScavTrap	trapC("trapC");
	
	// trapA.debug();
	// trapB.debug();
	// trapC.debug();

	trapA.attack("Frog");
	trapA.takeDamage(4);
	trapB.takeDamage(2);
	trapC.takeDamage(8);
	// trapA.debug();
	// trapB.debug();
	// trapC.debug();
	
	trapB.attack("Frog");
	trapB.beRepaired(2);
	trapC.guardGate();
	// trapA.debug();
	// trapB.debug();
	// trapC.debug();
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:12:20 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 20:23:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{ 
	ScavTrap	trapA("trapA");
	
	// trapA.debug();

	trapA.attack("Frog");
	trapA.takeDamage(4);
	// trapA.debug();
	
	trapA.beRepaired(2);
	// trapA.debug();
	
	trapA.guardGate();
	
	return (0);
}
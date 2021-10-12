/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:12:20 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 19:57:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	trapA("trapA");
	
	// trapA.debug();

	trapA.attack("Frog");
	trapA.takeDamage(4);
	// trapA.debug();
	
	trapA.beRepaired(2);
	// trapA.debug();

	trapA.highFiveGuys();
	
	return (0);
}
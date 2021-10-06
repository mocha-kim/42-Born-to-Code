/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:01:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 20:00:35 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;

	void	_prefix();

public:
	Zombie(std::string name);
	~Zombie();

	void	announce();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
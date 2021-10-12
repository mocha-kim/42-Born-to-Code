/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:22:58 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 17:55:30 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	virtual void	_prefix();
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	virtual ~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &op);

	void		guardGate();
};



#endif
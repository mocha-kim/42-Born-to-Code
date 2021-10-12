/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:53:33 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/12 19:19:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	virtual void	_prefix();
	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	virtual ~FragTrap();

	FragTrap	&operator=(const FragTrap &op);

	void		highFiveGuys();
};

#endif
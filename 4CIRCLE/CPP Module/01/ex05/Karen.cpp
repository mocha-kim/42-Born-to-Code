/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:29:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 00:44:53 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	int			idx;
	std::string	levels[] = { "debug", "info", "warning", "error" };
	void		(Karen::*pFunc[])() = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error };

	for (idx = 0; idx < 4; idx++)
		if (level == levels[idx])
			break ;
	if (idx == 4)
	{
		std::cout << "Error: Invaild level" << std::endl;
		return ;
	}
	(this->*pFunc[idx])();
}
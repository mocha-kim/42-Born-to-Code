/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:29:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 01:31:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() { this->filterLevel = 0; }

Karen::Karen(std::string level)
{
	int			idx;
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (idx = 0; idx < 4; idx++)
		if (level == levels[idx])
			break ;
	this->filterLevel = idx;
}

Karen::~Karen() {}

void	Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::_prefix(std::string level)
{
	std::cout << "[ ";
	for (int i = 0; i < level.length(); i++)
		std::cout << (char)std::toupper(level[i]);
	std::cout << " ]" << std::endl;
}

void	Karen::_complain(std::string level)
{
	int			idx;
	std::string	levels[] = { "debug", "info", "warning", "error" };
	void		(Karen::*pFunc[])() = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error };

	for (idx = 0; idx < 4; idx++)
		if (level == levels[idx])
			break ;
	this->_prefix(level);
	(this->*pFunc[idx])();
	std::cout << std::endl;
}

void	Karen::complain(std::string level)
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

void	Karen::filter()
{
	switch (this->filterLevel)
	{
	case 0:
		this->_complain("debug");
	case 1:
		this->_complain("info");
	case 2:
		this->_complain("warning");
	case 3:
		this->_complain("error");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
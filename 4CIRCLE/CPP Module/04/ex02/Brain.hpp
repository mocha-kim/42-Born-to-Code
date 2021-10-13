/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:14:05 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 19:13:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string	ideas[100];

	void	_prefix() const;

public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain	&operator=(const Brain &op);

	void	debug() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:28:36 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 01:24:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>

class Karen
{
private:
	int		filterLevel;
	
	void		debug();
	void		info();
	void		warning();
	void		error();
	void		_prefix(std::string level);
	void		_complain(std::string level);
	
public:
	Karen();
	Karen(std::string level);
	~Karen();
	
	void	complain(std::string level);
	void	filter();
};

#endif
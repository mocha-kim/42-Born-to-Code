/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:57:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/06 23:45:33 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class CppSed
{
private:
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	file;

public:
	CppSed();
	~CppSed();

	bool	setFile(std::string filename);
	bool	setString(std::string s1, std::string s2);
	void	replace();
};

#endif
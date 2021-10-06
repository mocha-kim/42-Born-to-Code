/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:30:37 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 00:26:30 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

CppSed::CppSed(){}

CppSed::~CppSed() {}

bool	CppSed::setFile(std::string filename)
{
	if (filename == "")
	{
		std::cout << "Error: filename cannot be empty string" << std::endl;
		return (false);
	}
	this->filename = filename;
	if (this->file.is_open())
		this->file.close();
	this->file.open(this->filename);
	if (!this->file.is_open())
	{
		std::cout << "Error: \"" << this->filename << "\" open failed" << std::endl;
		return (false);
	}
	std::cout << "> \"" << this->filename << "\" opened" << std::endl;
	return (true);
}

bool	CppSed::setString(std::string s1, std::string s2)
{
	if (s1 == "" || s2 == "")
	{
		std::cout << "Error: input string cannot be empty string" << std::endl;
		return (false);
	}
	this->s1 = s1;
	this->s2 = s2;
	std::cout << "> string set ok" << std::endl;
	return (true);
}

void	CppSed::replace()
{
	int				idx = 0;
	std::ofstream	out;
	std::string		result;
	std::string		outname;

	while (!this->file.eof())
	{
		std::string	str;
		std::getline(file, str);
		result.append(str);
		result.push_back('\n');
	}
	result.pop_back();
	this->file.close();
	
	while ((idx = result.find(this->s1)) != -1)
	{
		result.erase(idx, this->s1.length());
		result.insert(idx, this->s2);
	}
	
	outname = this->filename;
	for (int i = 0; i < outname.length(); i++)
		outname[i] = std::toupper(outname[i]);
	out.open(outname.append(".replace"));
	if (!out.is_open())
	{
		std::cout << "Error: output file open failed" << std::endl;
		return ;
	}
	out.write(result.c_str(), result.length());
	out.close();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:13:52 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/05 18:57:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->recentIdx = -1;
	this->isPbFull = false;
	for(int i = 0; i < 8; i++)
		this->contacts[i].setIndex(i);
}

Phonebook::~Phonebook(void) {}

int	Phonebook::AddContact(void)
{
	int			curIdx = 0;
	std::string	input;

	if (this->isPbFull)
	{
		std::cout << "The phonebook is full!" << std::endl;
		std::cout << "If new contact is added,";
		std::cout << " replace the oldest contact." << std::endl;
		while (true)
		{
			std::cout << "Wanna continue?(y/n) > ";
			std::getline(std::cin, input);
			if (input == "y" || input == "Y")
				break ;
			else if (input == "n" || input == "N")
				return (0);
		}
	}

	curIdx = this->recentIdx + 1;
	if (curIdx == 8)
		curIdx = 0;

	std::cin.clear();
	std::cout << "First Name? > ";
	if (!(std::getline(std::cin, input)))
		return (-1);
	this->contacts[curIdx].setFirstName(input);
	std::cout << "Last Name? > ";
	if (!(std::getline(std::cin, input)))
		return (-1);
	this->contacts[curIdx].setLastName(input);
	std::cout << "Nickname? > ";
	if (!(std::getline(std::cin, input)))
		return (-1);
	this->contacts[curIdx].setNickname(input);
	std::cout << "Phone Number? > ";
	if (!(std::getline(std::cin, input)))
		return (-1);
	this->contacts[curIdx].setPhoneNum(input);
	std::cout << "Darkest Secret? > ";
	if (!(std::getline(std::cin, input)))
		return (-1);
	this->contacts[curIdx].setSecret(input);

	if (curIdx == 7)
		this->isPbFull = true;
	this->recentIdx = curIdx;
	std::cout << "Add Complete!" << std::endl;
	return (0);
}

int	Phonebook::SearchPhonebook(void)
{
	int			idx;
	int			max = 8;
	std::string	str;

	std::cout << ".----------.----------.----------.----------." << std::endl;
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->isPbFull && (i > this->recentIdx))
		{
			max = i;
			if (max == 0)
				std::cout << "|     There is no contact in Phonebook.     |" << std::endl;
			break ;
		}
		str = std::to_string(this->contacts[i].getIndex());
		str = Phonebook::RefineInfo(str);
		std::cout << "|" << str;
		str = this->contacts[i].getFirstName();
		str = Phonebook::RefineInfo(str);
		std::cout << "|" << str;
		str = this->contacts[i].getLastName();
		str = Phonebook::RefineInfo(str);
		std::cout << "|" << str;
		str = this->contacts[i].getNickname();
		str = Phonebook::RefineInfo(str);
		std::cout << "|" << str;
		std::cout << "|" << std::endl;
	}
	std::cout << ".----------.----------.----------.----------." << std::endl;
	std::cout << "You can search contact by index";
	std::cout << "(or stop searching by '9')." << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::cin >> idx;
		if (idx == 9)
			break ;
		else if (idx >= 0 && idx < max)
			Phonebook::printContact(idx);
		else
			std::cout << "Invaild input.. try agin." << std::endl;
	}
	std::cin.ignore();
	return (0);
}

void	Phonebook::printContact(int idx)
{
	std::cout << "index: " << this->contacts[idx].getIndex() << std::endl;
	std::cout << "first name: " << this->contacts[idx].getFirstName() << std::endl;
	std::cout << "last name: " << this->contacts[idx].getLastName() << std::endl;
	std::cout << "nickname: " << this->contacts[idx].getNickname() << std::endl;
	std::cout << "phone number: " << this->contacts[idx].getPhoneNum() << std::endl;
	std::cout << "darkest secret: " << this->contacts[idx].getSecret() << std::endl;
}

std::string	Phonebook::RefineInfo(std::string str)
{
	int			blank = 0;

	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str.push_back('.');
	}
	else
	{
		blank = 10 - str.length();
		for (int i = 0; i < blank; i++)
			str.push_back(' ');
	}
	return str;
}
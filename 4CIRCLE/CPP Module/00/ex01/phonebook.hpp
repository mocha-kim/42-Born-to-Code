/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:13:50 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/05 16:51:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class Phonebook
{
private:
	int			recentIdx;
	bool		isPbFull;
	Contact		contacts[8];

public:
	Phonebook();
	~Phonebook();

	int			AddContact();
	int			SearchPhonebook();
	void		printContact(int idx);
	std::string	RefineInfo(std::string str);
};

#endif
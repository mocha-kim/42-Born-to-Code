/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:24:13 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/05 19:07:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	int			index;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNum;
	std::string	secret;

public:
	Contact();
	Contact(int index);
	virtual 	~Contact();

	void		setIndex(int index);
	void		setFirstName(std::string firstName);
	void		setLastName(std::string lastName);
	void		setNickname(std::string nickname);
	void		setPhoneNum(std::string phoneNum);
	void		setSecret(std::string secret);
	
	int			getIndex();
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNum();
	std::string	getSecret();
};

#endif
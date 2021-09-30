/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:57 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/30 22:09:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) { this->index = -1; }

Contact::~Contact(void) {}

void	Contact::setIndex(int index) { this->index = index; }
void	Contact::setFirstName(std::string first) { this->firstName = first; }
void	Contact::setLastName(std::string last) { this->lastName = last; }
void	Contact::setNickname(std::string nick) { this->nickname = nick; }
void	Contact::setPhoneNum(std::string phone) { this->phoneNum = phone; }
void	Contact::setSecret(std::string secret) { this->secret = secret; }

int	Contact::getIndex(void) { return this->index; }
std::string	Contact::getFirstName() { return this->firstName; }
std::string	Contact::getLastName() { return this->lastName; }
std::string	Contact::getNickname() { return this->nickname; }
std::string	Contact::getPhoneNum() { return this->phoneNum; }
std::string	Contact::getSecret() { return this->secret; }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:53:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 00:56:41 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	Form("Presidential Pardon Form", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	Form(copy)
{
	this->target = copy.target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	Form::operator=(copy);
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	Form::execute(bureaucrat);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}


/* ************************************************************************** */
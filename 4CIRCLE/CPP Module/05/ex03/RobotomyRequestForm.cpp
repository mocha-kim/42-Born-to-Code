/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:53:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 02:06:51 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	Form("Robotomy Request Form", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	Form(copy)
{
	this->target = copy.target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	Form::operator=(copy);
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	Form::execute(bureaucrat);
	srand(time(0));
	std::cout << "* VvrRRrrr vVVrrrrRrRRr vvvrrRrr *" << std::endl;
	if ((rand() % 100) < 50)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotization failed" << std::endl;
}


/* ************************************************************************** */
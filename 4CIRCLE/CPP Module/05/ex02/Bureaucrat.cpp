/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:38:20 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 15:24:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string const name, int grade):
	name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	name(other.name), grade(other.grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Bureaucrat::upGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void				Bureaucrat::downGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
		std::cout << this->name << " cannot sign " << form.getName()
			<< " because it is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->name << " signs " << form.getName() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << this->name << " cannot sign " << form.getName();
			std::cout << " because " << e.what() << std::endl;
		}
		
	}
}

void				Bureaucrat::executeForm(Form const & form)
{
	if (!form.getIsSigned())
		std::cout << this->name << " cannot sign " << form.getName()
			<< " because this form is unsigned" << std::endl;
	else if (form.getExecGrade() < this->grade)
		std::cout << this->name << " cannot execute " << form.getName()
				<< " because bureaucrat's grade is too low." << std::endl;
	else
	{
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}


/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade is too low";
}


/* ************************************************************************** */
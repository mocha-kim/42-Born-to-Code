/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:31:45 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 21:49:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string const name, int const sign_grade, int const exec_grade):
	name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other):
	name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &other)
{
	this->is_signed = other.is_signed;
	return *this;
}

std::ostream &operator<<(std::ostream & o, Form const &form)
{
	o << form.getName() << ", "
		<< (form.getIsSigned() ? "Signed" : "Unsigned")
		<< ", Sign grade: " << form.getSignGrade()
		<< ", Excute grade: " << form.getExecGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign_grade)
		this->is_signed = true;
	else if (this->is_signed)
		std::cout << bureaucrat.getName() << " cannot sign " << this->name
			<< " because it is already signed" << std::endl;
	else
		throw Form::GradeTooLowException();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->exec_grade);
}


/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return "Exception: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Exception: Grade is too low";
}


/* ************************************************************************** */
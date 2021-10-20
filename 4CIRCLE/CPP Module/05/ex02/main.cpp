/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:09:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 15:24:55 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	*personA = new Bureaucrat("personA", 100);
	Bureaucrat	*personB = new Bureaucrat("personB", 45);
	Bureaucrat	*personC = new Bureaucrat("personC", 10);
	Bureaucrat	*personD = new Bureaucrat("personD", 5);

	std::cout << "=====================Test 1: Shrubbery Creation Form=====================" << std::endl;
	ShrubberyCreationForm	*sh = new ShrubberyCreationForm("home");
	std::cout << *sh << std::endl;
	try
	{
		sh->execute(*personA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sh->beSigned(*personA);
		personA->executeForm(*sh);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *sh << std::endl;
	std::cout << std::endl;
	delete sh;
	
	std::cout << "======================Test 2: Robotomy Request Form======================" << std::endl;
	RobotomyRequestForm	*ro = new RobotomyRequestForm("robot");
	std::cout << *ro << std::endl;
	try
	{
		ro->execute(*personA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *ro << std::endl;
	try
	{
		personB->executeForm(*ro);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *ro << std::endl;
	try
	{
		ro->beSigned(*personB);
		personB->executeForm(*ro);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *ro << std::endl;
	std::cout << std::endl;
	delete ro;

	std::cout << "=====================Test 3: Presidential Pardon Form====================" << std::endl;
	PresidentialPardonForm	*pr = new PresidentialPardonForm("cardiB");
	std::cout << *pr << std::endl;
	try
	{
		pr->execute(*personC);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *pr << std::endl;
	try
	{
		personC->signForm(*pr);
		personC->executeForm(*pr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *pr << std::endl;
	try
	{
		pr->execute(*personD);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *pr << std::endl;
	delete pr;

	delete personA;
	delete personB;
	delete personC;
	delete personD;
}
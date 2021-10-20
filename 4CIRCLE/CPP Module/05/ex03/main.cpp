/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:09:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 15:34:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat man("LipJ", 1);
	Intern someRandomIntern;

	Form* scf;
	try
	{
		scf = someRandomIntern.makeForm("shrubbery creation", "garden");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		man.signForm(*scf);
		man.executeForm(*scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete scf;

	Form* rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Gabee");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		rrf->beSigned(man);
		rrf->execute(man);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
	
	Form* ppf;
	try
	{
		ppf = someRandomIntern.makeForm("presidential pardon", "Jessi");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ppf->beSigned(man);
		ppf->execute(man);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete ppf;

	try
	{
		Form *wrong = someRandomIntern.makeForm("wrong form", "noze");
		delete wrong;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
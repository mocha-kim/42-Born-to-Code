/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:09:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 02:06:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat man("LipJ", 1);
	Intern someRandomIntern;

	Form* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
	try
	{
		scf->beSigned(man);
		scf->execute(man);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete scf;

	Form* rrf = someRandomIntern.makeForm("robotomy request", "Gabee");
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
	
	Form* ppf = someRandomIntern.makeForm("presidential pardon", "Jessi");
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
}
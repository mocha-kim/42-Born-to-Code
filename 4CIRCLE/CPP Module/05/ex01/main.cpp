/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:09:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 21:52:21 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	bu1 = Bureaucrat("bu1", 10);
	Bureaucrat	bu2 = Bureaucrat("bu2", 150);
	Bureaucrat	bu3 = Bureaucrat("bu3", 100);
	Bureaucrat	bu4 = Bureaucrat("bu4", 150);

	std::cout << bu1 << std::endl;
	std::cout << bu2 << std::endl;
	std::cout << bu3 << std::endl;
	std::cout << std::endl;

	Form		fo1 = Form("form1", 50, 10);
	std::cout << fo1 << std::endl;
	try
	{
		fo1.beSigned(bu1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << fo1 << std::endl;
	std::cout << std::endl;

	Form		fo2 = Form("form2", 50, 10);
	std::cout << fo2 << std::endl;
	try
	{
		fo2.beSigned(bu2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << fo2 << std::endl;
	std::cout << std::endl;

	Form		fo3 = Form("form3", 100, 50);
	std::cout << fo3 << std::endl;
	bu3.signForm(fo3);
	bu4.signForm(fo3);
	std::cout << fo3 << std::endl;
	std::cout << std::endl;

	Form		fo4 = Form("form4", 100, 50);
	std::cout << fo4 << std::endl;
	bu4.signForm(fo4);
	std::cout << fo4 << std::endl;
	std::cout << std::endl;

	try
	{
		Form	low1 = Form("low1", 200, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form	low2 = Form("low2", 100, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form	high1 = Form("high1", 0, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form	high2 = Form("high2", 100, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}
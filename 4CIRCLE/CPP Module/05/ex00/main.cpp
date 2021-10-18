/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:25:46 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/18 21:03:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bu1 = Bureaucrat("bu1", 149);

		std::cout << bu1 << std::endl;
		bu1.downGrade();
		std::cout << bu1 << std::endl;
		bu1.downGrade();
		std::cout << bu1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	bu2 = Bureaucrat("bu2", 2);

		std::cout << bu2 << std::endl;
		bu2.upGrade();
		std::cout << bu2 << std::endl;
		bu2.upGrade();
		std::cout << bu2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	bu3 = Bureaucrat("bu3", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat	bu4 = Bureaucrat("bu4", 180);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
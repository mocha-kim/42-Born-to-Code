/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:32:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/23 22:11:37 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int	main()
{
	Array<int>			a1;
	Array<std::string>	a2(6);

	std::cout << "==============Test1: []accessing===============" << std::endl;
	try
	{
		a2[0] = "red";
		a2[1] = "orange";
		a2[2] = "yello";
		a2[3] = "green";
		a2[4] = "blue";
		a2[5] = "purple";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	for ( std::size_t i = 0; i < a2.size(); i++ )
	{
		std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "==========Test2: assignment operator===========" << std::endl;
	Array<std::string>	a3 = a2;

	for ( std::size_t i = 0; i < a3.size(); i++ )
	{
		std::cout << "a3[" << i << "] = " << a2[i] << ",\t";
		std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
	}
	std::cout << "size of a2 = " << a2.size() << std::endl;
	std::cout << "size of a3 = " << a3.size() << std::endl;
	std::cout << std::endl;

	std::cout << "============Test3: copy constructor============" << std::endl;
	Array<std::string>	a4(a3);

	for ( std::size_t i = 0; i < a4.size(); i++ )
	{
		std::cout << "a3[" << i << "] = " << a2[i] << ",\t";
		std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
	}
	std::cout << "size of a3 = " << a3.size() << std::endl;
	std::cout << "size of a4 = " << a4.size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "===============Test4: exception================" << std::endl;
	try
	{
		a4[7] = "exception";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
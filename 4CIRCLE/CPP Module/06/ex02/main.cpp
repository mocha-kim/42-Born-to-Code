/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:43:54 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 20:25:46 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

int	main()
{
	srand(time(0));

	std::cout << "===========Test1: a,b,c============" << std::endl;
	Base	*a = new A();
	Base	*b = new B();
	Base	*c = new C();

	identify(a);
		std::cout << "/";
	identify(*a);
	std::cout << std::endl;
	identify(b);
		std::cout << "/";
	identify(*b);
	std::cout << std::endl;
	identify(c);
		std::cout << "/";
	identify(*c);
	std::cout << std::endl;
	
	delete a;
	delete b;
	delete c;
	std::cout << std::endl;

	std::cout << "==========Test2: genarate==========" << std::endl;
	for (int i = 1; i < 43; i++)
	{
		Base	*tmp = generate();
		std::cout << (i < 10 ? "0" : "") << i << ") ";
		identify(tmp);
		std::cout << "/";
		identify(*tmp);
		std::cout << std::endl;
		delete tmp;
	}
	
	return (0);
}
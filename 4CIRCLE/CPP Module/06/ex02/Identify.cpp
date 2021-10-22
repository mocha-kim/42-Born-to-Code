/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:05:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/22 13:53:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

void identify(Base* p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a != 0)
		std::cout << "A";
	else if (b != 0)
		std::cout << "B";
	else if (c != 0)
		std::cout << "C";
}

void identify(Base& p)
{
	A	*a;
	B	*b;
	C	*c;

	try
	{
		a = dynamic_cast<A*>(&p);
		b = dynamic_cast<B*>(&p);
		c = dynamic_cast<C*>(&p);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (a != 0)
		std::cout << "A";
	else if (b != 0)
		std::cout << "B";
	else if (c != 0)
		std::cout << "C";
}


/*
** exception case
*/

	// try
	// {
	// 	C	&c2 = dynamic_cast<C&>(p);
	// 	(void)c2;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:05:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 20:14:00 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

void identify(Base* p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a != nullptr)
		std::cout << "A";
	else if (b != nullptr)
		std::cout << "B";
	else if (c != nullptr)
		std::cout << "C";
}

void identify(Base& p)
{
	A	*a = dynamic_cast<A*>(&p);
	B	*b = dynamic_cast<B*>(&p);
	C	*c = dynamic_cast<C*>(&p);

	if (a != nullptr)
		std::cout << "A";
	else if (b != nullptr)
		std::cout << "B";
	else if (c != nullptr)
		std::cout << "C";
}
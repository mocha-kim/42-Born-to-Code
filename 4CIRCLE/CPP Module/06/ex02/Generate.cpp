/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:04:53 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 20:10:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

Base	*generate()
{
	int	r = rand() % 99;

	if (r < 33)
		return (new A);
	else if (r >= 33 && r < 66)
		return (new B);
	else
		return (new C);
}
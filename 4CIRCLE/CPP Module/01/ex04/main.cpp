/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:56:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 00:26:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char* argv[])
{
	CppSed	sed;
	if (argc != 4)
	{
		std::cout << "Error: Invailed argument number" << std::endl;
		return (-1);
	}
	if (!sed.setString(argv[2], argv[3]))
		return (-1);
	if (!sed.setFile(argv[1]))
		return (-1);
	sed.replace();
	return (0);
}
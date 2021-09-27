/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:31:39 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/27 18:57:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int argc, char *argv[])
{
	std::string str;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
				std::cout << (char)std::toupper(str[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
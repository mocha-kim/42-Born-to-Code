/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:34:48 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 16:36:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Invalid arguments number" << std::endl;
	else
	{
		Convert con(argv[1]);
		try
		{
			con.convert();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
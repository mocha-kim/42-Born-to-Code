/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:50:29 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 01:11:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invaild argument number" << std::endl;
		return (0);
	}
	
	Karen	karen = Karen(argv[1]);
	karen.filter();
	
	return (0);
}
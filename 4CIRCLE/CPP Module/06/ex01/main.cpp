/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:19:06 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 19:42:46 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main()
{
	Data		*data1 = new Data(42, 42.042f, true, "42seoul");
	Data		*data2;
	uintptr_t	ptr;

	std::cout << *data1 << std::endl;
	ptr = serialize(data1);
	std::cout << "serialized ptr: " << ptr << std::endl;
	data2 = deserialize(ptr);
	std::cout << *data2 << std::endl;

	return (0);
}
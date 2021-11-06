/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:33 by sunhkim           #+#    #+#             */
/*   Updated: 2021/11/06 21:54:38 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int	main()
{
	std::cout << "=====Test1: simple=====" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "=====Test2: random=====" << std::endl;
	Span sp2 = Span(10002);
	std::vector<int> vec;
	srand(time(0));
	for (int i = 0; i < 10000; ++i) {
		vec.push_back(rand() % 1000000);
	}
	sp2.addNumber(vec.begin(), vec.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "=====Test3: minmax=====" << std::endl;
	sp2.addNumber(std::numeric_limits<int>::min());
	sp2.addNumber(std::numeric_limits<int>::max());

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:23:32 by sunhkim           #+#    #+#             */
/*   Updated: 2021/11/02 13:41:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>

int	main()
{
	std::vector<int>    vec;

	vec.push_back(42);
	vec.push_back(0);
	vec.push_back(99);
	vec.push_back(-42);

	std::cout << "=====Test1: find 42 in vector=====" << std::endl;
	try
	{
		std::vector<int>::iterator iter = easyfind(vec, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::deque<int>     deq;

	deq.push_back(420);
	deq.push_back(-24);
	deq.push_back(0);
	deq.push_back(-99);

	std::cout << "=====Test2: find 42 in deque======" << std::endl;
	try
	{
		std::deque<int>::iterator iter = easyfind(deq, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::list<int>      lst;

	lst.push_back(-42);
	lst.push_back(24);
	lst.push_back(42);
	lst.push_back(0);

	std::cout << "======Test3: find 42 in list======" << std::endl;
	try
	{
		std::list<int>::iterator iter = easyfind(lst, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	const int	num[] = {8, 88, 0, -88};
	std::set<int>       set(num, num + 4);
	std::multiset<int>  mset(num, num + 4);

	std::cout << "======Test4: find 42 in set=======" << std::endl;
	try
	{
		std::set<int>::iterator iter = easyfind(set, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "====Test5: find 42 in multiset====" << std::endl;
	try
	{
		std::multiset<int>::iterator iter = easyfind(mset, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
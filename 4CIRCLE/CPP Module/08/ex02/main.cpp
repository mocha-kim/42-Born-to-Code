/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:59:24 by sunhkim           #+#    #+#             */
/*   Updated: 2021/11/07 15:41:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=====Mutant Stack=====" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(-42);
	mstack.push(0);

	std::cout << "size: " << mstack.size() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << " ";
	++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << "=========List=========" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "top: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(42);
	list.push_back(-42);
	list.push_back(0);

	std::cout << "size: " << list.size() << std::endl;

	std::list<int>::iterator lst_it = list.begin();
	std::list<int>::iterator lst_ite = list.end();
	
	++lst_it;
	--lst_it;
	while (lst_it != lst_ite)
	{
	std::cout << *lst_it << " ";
	++lst_it;
	}
	std::cout << std::endl;
	return 0;
}
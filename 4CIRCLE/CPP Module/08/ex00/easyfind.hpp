/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:10:26 by sunhkim           #+#    #+#             */
/*   Updated: 2021/11/02 13:36:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
    virtual const char* what() const throw()
	{
		return ("Exception: Not found");
	}
};

template <typename T>
typename T::iterator  easyfind(T &arr, int n)
{
    typename T::iterator iter;
	if ((iter = std::find(arr.begin(), arr.end(), n)) != arr.end())
		return (iter);
	else
		throw NotFound();
}

#endif
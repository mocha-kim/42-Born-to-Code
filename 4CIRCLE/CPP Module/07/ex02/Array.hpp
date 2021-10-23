/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:32:13 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/23 22:05:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array() : _arr(new T[0]), _size(0) {};
	Array(unsigned int n) : _arr(new T[n]), _size(n) {};
	Array(Array const &copy)
	{
		this->_arr = new T[copy._size]();
		this->_size = copy._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = copy._arr[i];
	};
	~Array() { delete [] this->_arr; };

	Array	&operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		if (this->_arr)
		{
			delete [] this->_arr;
			this->_arr = 0;
			this->_arr = new T[other._size()];
			this->_size = other._size;
		}
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = other._arr[i];
		return (*this);
	};

	T		&operator[](unsigned int i)
	{
		if (i >= this->_size)
			throw std::exception();
		return (this->_arr[i]);
	};
	T const	&operator[](unsigned int i) const
	{
		if (i >= this->_size)
			throw std::exception();
		return (this->_arr[i]);
	}

	unsigned int	size() const { return (this->_size); };

private:
	T				*_arr;
	unsigned int	_size;
};

#endif
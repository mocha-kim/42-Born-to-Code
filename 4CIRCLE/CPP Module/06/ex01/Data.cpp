/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:04 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 19:42:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int i, float f, bool b, std::string str):
	i(i), f(f), b(b), str(str) {}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &o, const Data &data) {
	o << "Data: int(" << data.i << "), ";
	if (data.f - (int)data.f == (float)0)
		o << "float(" << (float)data.f << ".0f), ";
	else
		o << "float(" << (float)data.f << "f), ";
	o << "bool(" << (data.b ? "true" : "false") << "), ";
	o << "string(" << data.str << ")";
    return o;
}


/* ************************************************************************** */
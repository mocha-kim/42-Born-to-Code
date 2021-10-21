/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:07 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 19:37:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	int			i;
	float		f;
	bool		b;
	std::string	str;
	
	Data(int i, float f, bool b, std::string str);
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

std::ostream &operator<<(std::ostream &o, const Data &data);

#endif /* ************************************************************ DATA_H */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:33:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/11 15:49:36 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed 	&operator=(const Fixed& op);

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
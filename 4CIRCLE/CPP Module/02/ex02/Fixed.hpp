/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:33:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/11 17:11:53 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed 	&operator=(const Fixed& op);

	bool	operator>(Fixed const &other) const;
	bool	operator<(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;
	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;

	Fixed	operator+(Fixed const &other);
	Fixed	operator-(Fixed const &other);
	Fixed	operator*(Fixed const &other);
	Fixed	operator/(Fixed const &other);

	Fixed	operator++(int);
	Fixed	operator++();
	Fixed	operator--(int);
	Fixed	operator--();

	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
	int		toInt() const;
	float	toFloat() const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed& op);

Fixed			const &min(Fixed const &a, Fixed const &b);
Fixed			const &max(Fixed const &a, Fixed const &b);
Fixed			&min(Fixed &a, Fixed &b);
Fixed			&max(Fixed &a, Fixed &b);

#endif
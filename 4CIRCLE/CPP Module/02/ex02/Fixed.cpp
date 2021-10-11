/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:40:35 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/11 17:15:05 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	this->value = copy.getRawBits();
}

Fixed::Fixed(const int value)
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << Fixed::bits));
}

Fixed::~Fixed() {}

Fixed	&Fixed::operator=(const Fixed& op)
{
	this->value = op.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &other)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() + other.getRawBits());
	return (val);
}

Fixed	Fixed::operator-(Fixed const &other)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() - other.getRawBits());
	return (val);
}

Fixed	Fixed::operator*(Fixed const &other)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::bits));
	return (val);
}

Fixed	Fixed::operator/(Fixed const &other)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * (1 << Fixed::bits)) / tmp2);
	return (val);
}

Fixed	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

int		Fixed::getRawBits() const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int		Fixed::toInt() const
{
	return ((int)(this->value >> this->bits));
}

float	Fixed::toFloat() const
{
	return ((float)(this->value) / (float)(1 << this->bits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed& op)
{
	out << op.toFloat();
	return (out);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed const &min(Fixed const &a, Fixed const &b)
{
	return (Fixed::min(a, b));
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (Fixed::min(a, b));
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const &max(Fixed const &a, Fixed const &b)
{
	return (Fixed::max(a, b));
}

Fixed &max(Fixed &a, Fixed &b)
{
	return (Fixed::max(a, b));
}
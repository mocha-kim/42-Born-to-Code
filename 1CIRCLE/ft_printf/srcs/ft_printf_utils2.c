/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:03:43 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/30 19:33:44 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_padding(int n, char c)
{
	int count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}

int		ft_count_digit(unsigned long int n)
{
	if (!(n / 16))
		return (1);
	else
		return (ft_count_digit(n / 16) + 1);
}

char	*ft_itoa_base(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = ft_count_digit(n);
	if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

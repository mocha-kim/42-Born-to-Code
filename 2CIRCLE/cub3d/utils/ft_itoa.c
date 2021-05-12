/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:46:18 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/12 17:46:19 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	ft_abs(int n)
{
	long long n2;

	n2 = n;
	if (n < 0)
		return (n2 * -1);
	return (n2);
}

int			ft_intlen(int n)
{
	int			len;
	long long	n2;

	len = 1;
	n2 = ft_abs(n);
	while (n2 /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char		*str;
	long long	n2;
	int			i;
	int			len;

	n2 = ft_abs(n);
	i = 1;
	len = ft_intlen(n);
	if (n < 0)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (i <= len)
	{
		if (str[len - i] != '-')
			str[len - i] = (n2 % 10) + '0';
		n2 /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

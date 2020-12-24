/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:35:43 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/24 21:11:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_str_len(long nb)
{
	int		length;

	length = 0;
	if (nb < 0)
	{
		nb *= -1;
		length++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	n_long;
	int		length;

	n_long = n;
	length = get_str_len(n_long);
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	result[length--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[length] = '0' + (n % 10);
		n /= 10;
		length--;
	}
	return (result);
}

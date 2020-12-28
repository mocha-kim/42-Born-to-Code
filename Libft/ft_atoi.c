/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:35:38 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 21:13:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
/*
int		check_long(long long result, int sign)
{
	printf("check : %lld\n", result);
	if (result > 2147483647)
		return (-1);
	else if (result < -2147483648)
		return (0);
	else
		return (result * sign);
}
*/
int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v'))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return(result * sign);
}


int		main()
{
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("99999999999999999999999999"));
	return (0);
}

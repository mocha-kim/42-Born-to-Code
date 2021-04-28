/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:48:57 by sunhkim           #+#    #+#             */
/*   Updated: 2021/04/28 20:49:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_atoi(const char *str)
{
	long long	result;

	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		return (-1);
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - '0');
		if (result > 2147483647)
			return (2147483647);
	}
	return (result);
}

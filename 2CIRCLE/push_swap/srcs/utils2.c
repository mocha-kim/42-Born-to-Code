/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:21:22 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 14:07:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_list_clear(t_node **head)
{
	t_node	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

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
	if (result >= 2147483648 || result < -2147483648)
		return (sign * -127);
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

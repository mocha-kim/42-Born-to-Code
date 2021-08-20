/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:36:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 15:33:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char			*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*result;

	if (!s1)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (0);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
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

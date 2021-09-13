/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:16:39 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/13 18:50:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_err(int error)
{
	if (error == ERR_ARG)
		write(1, "Error : Invalid Arguments\n", 27);
	else if (error == ERR_MEM)
		write(1, "Error : Malloc Error\n", 22);
	else if (error == ERR_PTH)
		write(1, "Error : Pthread not returned\n", 30);
	else if (error == ERR_PMU)
		write(1, "Error : Mutex init failed\n", 30);
	return (errno);
}

void	print_state(t_info *info, t_philo *philo, char *str, int *sig)
{
	if (check_stop(info, sig) == 0)
		return ;
	pthread_mutex_lock(&(info->m_write));
	printf("%lums %d %s\n", get_time(info), philo->id + 1, str);
	pthread_mutex_unlock(&(info->m_write));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *str)
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

int	ft_atoi(const char *str)
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
		return (sign * -1);
	return (result * sign);
}

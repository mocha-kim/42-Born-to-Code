/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:55:55 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/25 16:49:56 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_dead(t_info *info, t_philo *philo, long int t_n, long int t_l)
{
	if (t_l + info->die < t_n)
	{
		pthread_mutex_lock(&info->m_stop);
		info->sig = 1;
		pthread_mutex_unlock(&info->m_stop);
		pthread_mutex_lock(&info->m_write);
		if (!(info->has_6th_arg))
			printf("%lu %d %s\n", get_time(info), philo->id + 1, "is died");
		pthread_mutex_unlock(&info->m_write);
		return (0);
	}
	return (1);
}

int	check_death(t_info *info, int *sig)
{
	int			i;
	int			is_alive;
	long int	time_now;
	long int	time_last;

	i = 0;
	if (*sig == 1)
		return (0);
	time_now = get_time(info);
	while (i < info->num)
	{
		pthread_mutex_lock(&(info->philos[i].eating));
		time_last = info->philos[i].time_hunger;
		is_alive = is_dead(info, &(info->philos[i]), time_now, time_last);
		pthread_mutex_unlock(&(info->philos[i].eating));
		if (!is_alive)
		{
			info->sig = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_stop(t_info *info, int *sig)
{
	pthread_mutex_lock(&info->m_stop);
	*sig = info->sig;
	pthread_mutex_unlock(&info->m_stop);
	return (*sig);
}

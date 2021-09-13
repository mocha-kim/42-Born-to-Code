/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:11:02 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/13 20:06:26 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_info *info, int *sig)
{
	
}

int	check_stop(t_info *info, int *sig)
{
	pthread_mutex_lock(&info->m_stop);
	*sig = info->sig;
	pthread_mutex_unlock(&info->m_stop);
	if (*sig)
		return (0);
	return (1);
}

void	philo_alone(t_info *info)
{
	printf("%lums %d has taken a fork\n", get_time(info), 1);
	sleep_time(info, info->die);
	printf("%lums %d is dead\n", get_time(info), 1);
}

void	philo_check_join(t_info *info, t_philo **philos)
{
	int	i;
	int	sig;
	
	i = 0;
	sig = 0;
	while (1)
	{
		if (check_death(info, &sig) == 0)
			break ;
	}
	while (i < info->num)
	{
		pthread_join(philos[i]->t_id, NULL);
		i++;
	}
}

int	philosophers(t_info *info, t_philo **philos)
{
	int	i;
	struct timeval	t;

	i = 0;
	gettimeofday(&t, NULL);
	info->time_start = t.tv_sec * 1000 + t.tv_usec / 1000;
	while (i < info->num)
	{
		philos[i]->info = info;
		if (!pthread_create(&philos[i]->t_id, NULL, thread, &philos[i]))
			return (print_err(ERR_PTH));
		i = i + 2;
		if (i >= info->num && i % 2 == 0)
		{
			i = 1;
			usleep(300);
		}
	}
	philo_check_join(info, philos);
	return (1);
}
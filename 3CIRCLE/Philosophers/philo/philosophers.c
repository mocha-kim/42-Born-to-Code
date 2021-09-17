/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:11:02 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/17 17:50:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_alone(t_info *info)
{
	struct timeval	t;
	
	gettimeofday(&t, NULL);
	info->time_start = t.tv_sec * 1000 + t.tv_usec / 1000;
	printf("%lu %d has taken a fork\n", get_time(info), 1);
	sleep_time(info, info->die);
	printf("%lu %d is dead\n", get_time(info), 1);
}

static void	philo_check_join(t_info *info)
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
		pthread_join(info->philos[i].t_id, NULL);
		i++;
	}
}

int	philosophers(t_info *info)
{
	int	i;
	struct timeval	t;

	i = 0;
	gettimeofday(&t, NULL);
	info->time_start = t.tv_sec * 1000 + t.tv_usec / 1000;
	while (i < info->num)
	{
		info->philos[i].info = info;
		pthread_create(&info->philos[i].t_id, NULL, thread, &(info->philos[i]));
		i = i + 2;
		if (i >= info->num && i % 2 == 0)
		{
			i = 1;
			usleep(300);
		}
	}
	philo_check_join(info);
	return (1);
}
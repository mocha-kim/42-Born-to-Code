/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:52:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/17 18:03:19 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_routine(t_info *info, t_philo *philo, int *sig)
{
	pthread_mutex_lock(philo->fork_r);
	print_state(info, philo, "has taken a fork", sig);
	pthread_mutex_lock(philo->fork_l);
	print_state(info, philo, "has taken a fork", sig);
	pthread_mutex_lock(&(philo->eating));
	print_state(info, philo, "is eating", sig);
	philo->time_hunger = get_time(info);
	sleep_time(info, info->eat);
	pthread_mutex_unlock(&(philo->eating));
	(philo->num_eat)++;
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
	print_state(info, philo, "is sleeping", sig);
	sleep_time(info, info->sleep);
	print_state(info, philo, "is thinking", sig);
	usleep(200);
	if (check_stop(info, sig))
		return (0);
	return (1);
}

void	*thread(void *data)
{
	t_philo	*philo;
	t_info	*info;
	int		sig;

	philo = (t_philo *)data;
	info = philo->info;
	philo->num_eat = 0;
	sig = 0;
	while ((info->has_6th_arg && (philo->num_eat < info->must_eat))
			|| (!(info->has_6th_arg) && !sig))
	{
		if (!philo_routine(info, philo, &sig))
			return (NULL);
	}
	return (NULL);
}

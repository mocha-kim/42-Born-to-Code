/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:52:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/10 15:36:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_routine(t_info *info, t_philo *philo, int sig)
{
	
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
		if (!philo_routine(info, philo, sig))
			return ;
	}
}

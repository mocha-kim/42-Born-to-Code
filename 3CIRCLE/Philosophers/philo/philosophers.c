/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:11:02 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/10 16:37:04 by sunhkim          ###   ########.fr       */
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

int	philosophers(t_info *info, t_philo **philos)
{
	int	i;
	int	sig;

	i = 0;
	while (i < info->num)
	{
		philos[i]->info = info;
		if (!pthread_create(&philos[i]->t_id, NULL, thread, &philos[i]))
			return (print_err(ERR_PTH));
		i++;
	}
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
	return (1);
}
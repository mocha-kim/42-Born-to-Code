/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:12:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/16 18:26:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_info(t_info *info)
{
	info->num = 0;
	info->die = 0;
	info->eat = 0;
	info->sleep = 0;
	info->must_eat = 0;
	info->has_6th_arg = 0;
	info->sig = 0;
	info->time_start = 0;
}

int		init_info_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(info->m_write), NULL))
		return (print_err(ERR_PMU));
	if (pthread_mutex_init(&(info->m_stop), NULL))
		return (print_err(ERR_PMU));
	while (i < info->num)
	{
		if (pthread_mutex_init(&(info->m_forks[i]), NULL))
			return (print_err(ERR_PMU));
		i++;
	}
	return (0);
}

void	init_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		info->philos[i].id = i;
		info->philos[i].num_eat = 0;
		info->philos[i].time_hunger = 0;
		i++;
	}
}

int		init_philos_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		if (pthread_mutex_init(&(info->philos[i].eating), NULL))
			return (print_err(ERR_PMU));
		info->philos[i].fork_r = &(info->m_forks[i]);
		if (i == info->num - 1)
			info->philos[i].fork_l = &(info->m_forks[0]);
		else
			info->philos[i].fork_l = &(info->m_forks[i + 1]);
		i++;
	}
	return (0);
}
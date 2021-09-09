/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:52:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/09 18:24:05 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread(void *data)
{

}

int	threading(t_info *info, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		philos[i]->info = info;
		if (pthread_create(philos[i]->t_id, NULL, thread, philos[i]) != 0)
			return (ft_exit("Pthread did not return 0\n"));
		i++;
	}
	return (1);
}
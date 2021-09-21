/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:44:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/21 19:08:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_time(t_info *info, long int time)
{
	unsigned int	start;
	unsigned int	current;
	int				sig;

	start = get_time(info);
	current = start;
	sig = 0;
	while (current < start + time)
	{
		usleep(100);
		current = get_time(info);
		if (info->num != 1)
		{
			if (check_stop(info, &sig) && time != info->eat)
				break ;
		}
	}
}

long int	get_time(t_info *info)
{
	long int			time;
	struct timeval		t;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000 - info->time_start;
	return (time);
}

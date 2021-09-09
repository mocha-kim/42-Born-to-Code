/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:11:02 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/09 14:04:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosophers(t_info *info, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		printf("philo %d\n", philos[i]->id);
		i++;
	}
	return (1);
}
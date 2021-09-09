/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:52:10 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/09 14:57:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_info(t_info *info)
{
	info->num = 0;
	info->die = 0;
	info->eat = 0;
	info->sleep = 0;
	info->must_eat = 0;
}

static void	init_philos(t_info *info, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->id = i;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	**philos;

	init_info(&info);
	philos = NULL;
	if (!(argc == 6 || argc == 5))
		return (print_err(ERR_ARG));
	if (!parse_args(&info, argc, argv))
		return (print_err(ERR_ARG));
	philos = malloc(sizeof(t_philo *) * info.num);
	if (philos != NULL)
	{
		init_philos(&info, philos);
		philosophers(&info, philos);
	}
	return (0);
}
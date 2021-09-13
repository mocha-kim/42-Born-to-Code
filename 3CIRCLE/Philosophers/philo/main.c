/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:52:10 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/13 20:06:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		init_philos_mutex(&info, philos);
		philosophers(&info, philos);
	}
	return (0);
}
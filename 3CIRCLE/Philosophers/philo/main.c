/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:52:10 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/21 19:06:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info);
	if (!(argc == 6 || argc == 5))
		return (print_err(ERR_ARG));
	if (!parse_args(&info, argc, argv))
		return (print_err(ERR_ARG));
	init_philos(&info);
	if (info.num == 1)
	{
		philo_alone(&info);
		return (0);
	}
	init_philos_mutex(&info);
	philosophers(&info);
	return (0);
}

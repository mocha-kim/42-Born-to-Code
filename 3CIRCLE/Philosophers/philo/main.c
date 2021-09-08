/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:52:10 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/08 19:02:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if ((argc == 6 || argc == 5) && parse_args(&philo, argv))
		philosophers(&philo);
	else
		return (print_err(ERR_ARG));
	return (0);
}
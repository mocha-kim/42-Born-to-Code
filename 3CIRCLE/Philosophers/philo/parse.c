/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:24:39 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/13 18:13:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int check_args(t_info *info)
{
	if (info->num < 1 || info->num < 1 || info->die < 1
		|| info->eat < 1 || info->sleep < 1)
		return (0);
	if (info->has_6th_arg == 1 && info->must_eat < 1)
		return (0);
	return (1);
}

int	parse_args(t_info *info, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	info->num = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->has_6th_arg = 1;
		info->must_eat = ft_atoi(argv[5]);
	}
	if (!check_args(info))
		return (0);
	init_info_mutex(info);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:26:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 15:39:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_args(int i, char *argv[], int *num)
{
	int j;

	if (argv[i][0] == '-' && num[i - 1] > 0)
		return (-1);
	if ((argv[i][0] == '+' || ft_isdigit(argv[i][0])) && num[i - 1] < 0)
		return (-1);
	j = 0;
	while (j < i - 1)
	{
		if (num[i - 1] == num[j])
			return (-1);
		j++;
	}
	return (1);
}

static int	save_args(int argc, int *num, t_info *info)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_list_add_back(&(info->a.top), ft_node_new(num[i - 1]));
		i++;
	}
	info->a.size = argc - 1;
	return (1);
}

int			check_save_args(int argc, char *argv[], t_info *info)
{
	int	i;
	int	*num;

	i = 1;
	num = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (-1);
		num[i - 1] = ft_atoi(argv[i]);
		if (check_args(i, argv, num) == -1)
			return (-1);
		i++;
	}
	save_args(argc, num, info);
	return (1);
}
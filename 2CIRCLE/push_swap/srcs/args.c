/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:26:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 15:58:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_args(int *num, t_node **list, char *str)
{
	t_node	*tmp;

	*num = ft_atoi(str);
	if (str[0] == '-' && *num > 0)
		return (-1);
	if ((str[0] == '+' || ft_isdigit(str[0])) && *num < 0)
		return (-1);
	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->num == *num)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (1);
}

int			check_save_args(int argc, char *argv[], t_info *info)
{
	int		i;
	int		j;
	int		num;
	int		args_n;
	char	**tmp;

	i = 1;
	args_n = 0;
	while (i < argc)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			if (check_args(&num, &(info->a.top), tmp[j]) == -1)
				return (-1);
			ft_list_add_back(&(info->a.top), ft_node_new(num));
			j++;
		}
		args_n += j;
		i++;
	}
	info->a.size = args_n;
	return (1);
}
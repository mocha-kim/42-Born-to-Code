/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:02:18 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 15:52:40 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_info(t_info *info)
{
	info->a.size = 0;
	info->a.top = NULL;
	info->b.size = 0;
	info->b.top = NULL;
}

void	clear_info(t_info *info)
{
	if (info->a.top)
		ft_list_clear(&(info->a.top));
	if (info->b.top)
		ft_list_clear(&(info->b.top));
}

int		main(int argc, char *argv[])
{
	t_info info;

	init_info(&info);
	if (argc == 1)
		return (0);
	if (check_save_args(argc, argv, &info) == -1)
	{
		write(1, "Error\n", 7);
		clear_info(&info);
		return (0);
	}
	push_swap(&info);

	t_node *tmp;
	tmp = info.a.top;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");

	clear_info(&info);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:49:25 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 17:47:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_num(int *num, int size)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (i < size - 1)
	{
		if (num[i] <= num[i + 1])
			i++;
		else
		{
			tmp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = tmp;
			i = 0;
		}
	}
}

static int	find_mid_pivot(t_info *info, int *pivot, char name)
{
	int		i;
	int		stack_size;
	int		*num;
	t_node	*tmp;

	tmp = (name == 'a') ? info->a.top : info->b.top;
	i = 0;
	stack_size = (name == 'a') ? info->a.size : info->b.size;
	num = malloc(sizeof(int) * (stack_size + 1));
	if (!num)
		return (-1);
	while (i < stack_size)
	{
		num[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_num(num, stack_size);
	*pivot = num[stack_size / 2];
	free(num);
	return (1);
}

void		sort_a()
{

}

void		sort_b()
{

}

int			solve(t_info *info)
{
	if (info->a.size == 1 || check_sorted_stack(&(info->a), 1))
		return ;
	if (info->a.size == 2)
	{
		if (info->b.size >= 2 && info->b.top->num < info->b.top->next->num)
		{
			swap_ss(&(info->a), &(info->b));
			return (1);
		}
		swap_sx(&(info->a), SA);
		return (1);
	}
	if (info->a.size == 3)
	{
		solve_3(info, 'a');
		return (1);
	}
	sort_a();
	solve(info);
	sort_b();
	return (1);
}
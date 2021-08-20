/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:31:46 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:31:20 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	can_return_a(t_info *info, int size)
{
	if (size <= 1 || check_sorted_stack(&(info->a), 1, size))
		return (1);
	else if (size == 2)
	{
		if (info->a.top->num > info->a.top->next->num)
			swap_sx(&(info->buf), &(info->a), SA);
		return (1);
	}
	return (0);
}

static void	rotate_push_a(t_sort *sort, t_info *info, int size)
{
	int		i;
	int		p1;
	int		p2;

	i = 0;
	find_pivots(&(info->a), &p1, &p2, size);
	while (i < size)
	{
		if (info->a.top->num >= p2)
		{
			rotate_rx(&(info->buf), &(info->a), RA);
			(sort->ra_num)++;
		}
		else
		{
			push_pb(&(info->buf), &(info->a), &(info->b));
			(sort->pb_num)++;
			if (info->b.top && (info->b.top->num >= p1))
			{
				rotate_rx(&(info->buf), &(info->b), RB);
				(sort->rb_num)++;
			}
		}
		i++;
	}
}

void	sort_a(t_info *info, int size)
{
	int		i;
	t_sort	sort;

	if (can_return_a(info, size))
		return ;
	init_sort_info(&sort);
	rotate_push_a(&sort, info, size);
	i = 0;
	while ((sort.ra_num != 0) && (i < (sort.ra_num % info->a.size)))
	{
		r_rotate_rx(&(info->buf), &(info->a), RRA);
		i++;
	}
	i = 0;
	while ((sort.rb_num != 0) && (i < (sort.rb_num % info->b.size)))
	{
		r_rotate_rx(&(info->buf), &(info->b), RRB);
		i++;
	}
	sort_a(info, sort.ra_num);
	sort_b(info, sort.rb_num);
	sort_b(info, sort.pb_num - sort.rb_num);
}

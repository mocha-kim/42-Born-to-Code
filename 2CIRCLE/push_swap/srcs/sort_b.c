/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:31:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 15:46:10 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	can_return_b(t_info *info, int size)
{
	if (size == 0)
		return (1);
	else if (size == 1)
	{
		push_pa(&(info->buf), &(info->a), &(info->b));
		return (1);
	}
	else if (size == 2)
	{
		if (info->b.top->num < info->b.top->next->num)
			swap_sx(&(info->buf), &(info->b), SB);
		push_pa(&(info->buf), &(info->a), &(info->b));
		push_pa(&(info->buf), &(info->a), &(info->b));
		return (1);
	}
	else if (check_sorted_stack(&(info->b), 0, size))
	{
		while (size > 0)
		{
			push_pa(&(info->buf), &(info->a), &(info->b));
			size--;
		}
		return (1);
	}
	return (0);
}

static void	rotate_push_b(t_sort *sort, t_info *info, int size)
{
	int		i;
	int		p1;
	int		p2;

	find_pivots(&(info->b), &p1, &p2, size);
	i = 0;
	while (i < size)
	{
		if (info->b.top->num < p1)
		{
			rotate_rx(&(info->buf), &(info->b), RB);
			(sort->rb_num)++;
		}
		else
		{
			push_pa(&(info->buf), &(info->a), &(info->b));
			(sort->pa_num)++;
			if (info->a.top && (info->a.top->num < p2))
			{
				rotate_rx(&(info->buf), &(info->a), RA);
				(sort->ra_num)++;
			}
		}
		i++;
	}
}

void		sort_b(t_info *info, int size)
{
	int		i;
	t_sort	sort;

	if (can_return_b(info, size))
		return ;
	init_sort_info(&sort);
	rotate_push_b(&sort, info, size);
	sort_a(info, sort.pa_num - sort.ra_num);
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
}
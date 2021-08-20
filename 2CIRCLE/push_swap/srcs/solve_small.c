/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:35:49 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:34:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_2(t_info *info)
{
	if (info->a.top->num > info->a.top->next->num)
		swap_sx(&(info->buf), &(info->a), SA);
}

static void	solve_3(t_info *info)
{
	int		max;
	t_stack	*stack;

	stack = &(info->a);
	find_max(&max, stack, 3);
	while (!check_sorted_stack(stack, 1, 3))
	{
		if (stack->top->num == max)
			rotate_rx(&(info->buf), stack, RA);
		else if (stack->top->next->num == max)
			r_rotate_rx(&(info->buf), stack, RRA);
		else
			swap_sx(&(info->buf), stack, SA);
	}
}

static void	solve_4(t_info *info)
{
	int		min;
	t_stack	*a;

	a = &(info->a);
	find_min(&min, a, 4);
	while (a->top->num != min)
		rotate_rx(&(info->buf), a, RA);
	push_pb(&(info->buf), &(info->a), &(info->b));
	solve_3(info);
	push_pa(&(info->buf), &(info->a), &(info->b));
}

static void	solve_5(t_info *info)
{
	int		i;
	int		min;
	int		max;
	t_stack	*a;

	a = &(info->a);
	find_min_max(&min, &max, a, 5);
	i = 0;
	while (i <= a->size)
	{
		if (a->top->num == min || a->top->num == max)
			push_pb(&(info->buf), &(info->a), &(info->b));
		else
			rotate_rx(&(info->buf), a, RA);
		i++;
	}
	solve_3(info);
	if (info->b.top->num == max)
		rotate_rx(&(info->buf), &(info->b), RB);
	push_pa(&(info->buf), &(info->a), &(info->b));
	push_pa(&(info->buf), &(info->a), &(info->b));
	rotate_rx(&(info->buf), a, RA);
}

void	solve_small(t_info *info)
{
	if (info->a.size == 2)
		solve_2(info);
	else if (info->a.size == 3)
		solve_3(info);
	else if (info->a.size == 4)
		solve_4(info);
	else if (info->a.size == 5)
		solve_5(info);
}

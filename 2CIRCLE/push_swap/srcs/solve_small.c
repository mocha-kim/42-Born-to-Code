/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:35:49 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 17:23:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		solve_2(t_info *info)
{
	if (info->a.top->num > info->a.top->next->num)
		swap_sx(&(info->a), SA);
}

void			solve_3(t_info *info, char name)
{
	int		max;
	t_stack	*stack;

	stack = (name == 'a') ? &(info->a) : &(info->b);
	find_max(&max, stack);
	while (!check_sorted_stack(stack, 1))
	{
		if (stack->top->num == max)
			(name == 'a') ? rotate_rx(stack, RA) : rotate_rx(stack, RB);
		else if (stack->top->next->num == max)
			(name == 'a') ? r_rotate_rx(stack, RRA) : r_rotate_rx(stack, RRB);
		else
			(name == 'a') ? swap_sx(stack, SA) : swap_sx(stack, SB);
	}
}

static void		solve_4(t_info *info)
{
	t_stack *a;
	int		min;

	a = &(info->a);
	find_min(&min, a);
	while (a->top->num != min)
		rotate_rx(a, RA);
	push_pb(&(info->a), &(info->b));
	solve_3(info, 'a');
	push_pa(&(info->a), &(info->b));
}

static void		solve_5(t_info *info)
{
	t_stack *a;
	int		min;
	int		max;
	int		i;

	a = &(info->a);
	find_min_max(&min, &max, a);
	i = 0;
	while (i <= a->size)
	{
		if (a->top->num == min || a->top->num == max)
			push_pb(&(info->a), &(info->b));
		else
			rotate_rx(a, RA);
		i++;
	}
	solve_3(info, 'a');
	if (info->b.top->num == max)
		rotate_rx(&(info->b), RB);
	push_pa(&(info->a), &(info->b));
	push_pa(&(info->a), &(info->b));
	rotate_rx(a, RA);
}

void			solve_small(t_info *info)
{
	if (info->a.size == 2)
		solve_2(info);
	else if (info->a.size == 3)
		solve_3(info, 'a');
	else if (info->a.size == 4)
		solve_4(info);
	else if (info->a.size == 5)
		solve_5(info);
}
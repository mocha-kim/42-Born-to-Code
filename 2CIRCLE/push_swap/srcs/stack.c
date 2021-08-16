/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:09:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/16 16:43:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sorted_stack(t_stack *stack, int dir)
{
	t_node *tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (dir && tmp->num < tmp->next->num)
		{
			tmp = tmp->next;
			continue ;
		}
		else if (!dir && tmp->num > tmp->next->num)
		{
			tmp = tmp->next;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

void	find_min(int *min, t_stack *stack)
{
	t_node		*tmp;

	*min = 0;
	tmp = stack->top;
	*min = stack->top->num;
	while (tmp)
	{
		if (tmp->num < *min)
			*min = tmp->num;
		tmp = tmp->next;
	}
}

void	find_max(int *max, t_stack *stack)
{
	t_node		*tmp;

	*max = 0;
	tmp = stack->top;
	*max = stack->top->num;
	while (tmp)
	{
		if (tmp->num > *max)
			*max = tmp->num;
		tmp = tmp->next;
	}
}

void	find_min_max(int *min, int *max, t_stack *stack)
{
	find_max(max, stack);
	find_min(min, stack);
}
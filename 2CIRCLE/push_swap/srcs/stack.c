/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:09:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:35:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted_stack(t_stack *stack, int dir, int size)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->top;
	while (i < size - 1)
	{
		if ((dir && tmp->num < tmp->next->num)
			|| (!dir && tmp->num > tmp->next->num))
		{
			tmp = tmp->next;
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

void	find_min(int *min, t_stack *stack, int size)
{
	int			i;
	t_node		*tmp;

	*min = 0;
	tmp = stack->top;
	*min = stack->top->num;
	i = 0;
	while (i < size)
	{
		if (tmp->num < *min)
			*min = tmp->num;
		tmp = tmp->next;
		i++;
	}
}

void	find_max(int *max, t_stack *stack, int size)
{
	int			i;
	t_node		*tmp;

	*max = 0;
	tmp = stack->top;
	*max = stack->top->num;
	i = 0;
	while (i < size)
	{
		if (tmp->num > *max)
			*max = tmp->num;
		tmp = tmp->next;
		i++;
	}
}

void	find_min_max(int *min, int *max, t_stack *stack, int size)
{
	find_max(max, stack, size);
	find_min(min, stack, size);
}

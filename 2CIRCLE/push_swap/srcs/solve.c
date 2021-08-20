/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:49:25 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 15:35:19 by sunhkim          ###   ########.fr       */
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

int			find_pivots(t_stack *stack, int *p1, int *p2, int size)
{
	int		i;
	int		*num;
	t_node	*tmp;

	tmp = stack->top;
	i = 0;
	num = malloc(sizeof(int) * (size + 1));
	if (!num)
		return (-1);
	while (i < size)
	{
		num[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_num(num, size);
	*p1 = num[size / 3];
	*p2 = num[size / 3 * 2];
	free(num);
	return (1);
}

void		init_sort_info(t_sort *sort)
{
	sort->ra_num = 0;
	sort->rb_num = 0;
	sort->pa_num = 0;
	sort->pb_num = 0;
}

int			solve(t_info *info)
{
	sort_a(info, info->a.size);
	return (1);
}
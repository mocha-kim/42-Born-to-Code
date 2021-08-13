/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:49:25 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 17:33:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_mid_pivot(int *pivot, t_info *info)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = info->a.top;
	while (i < info->a.size / 2)
	{
		tmp = tmp->next;
		i++;
	}
	*pivot = tmp->num;
	printf("pivot: %d\n", *pivot);
}

void	push_less(int *p_num, int pivot, t_info *info)
{
	int		i;
	int		size;

	*p_num = 0;
	i = 0;
	size = info->a.size;
	while (i < size)
	{
		if (info->a.top->num > pivot)
		{
			push_pb(&(info->a), &(info->b));
			(*p_num)++;
		}
		else
			rotate_rx(&(info->a), RA);
		i++;
	}
}

void	solve_medium(t_info *info)
{
	int		pivot;
	int		p_num;

	printf("> in, size: %d\n", info->a.size);

	t_node *tmp;
	tmp = info->a.top;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
	
	if (info->a.size == 1)
		return ;
	else if (info->a.size == 2)
	{
		if (info->a.top->num > info->a.top->next->num)
			swap_sx(&(info->a), SA);
		return ;
	}
	else if (check_sorted_stack(&(info->a)))
		return ;
	if (info->b.size == 2)
	{
		if (info->b.top->num > info->b.top->next->num)
			swap_sx(&(info->b), SB);
	}
	find_mid_pivot(&pivot, info);
	push_less(&p_num, pivot, info);
	solve_medium(info);
	while (p_num)
	{
		push_pa(&(info->a), &(info->b));
		p_num--;
	}
}
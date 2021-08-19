/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:49:25 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/19 16:45:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_debug(t_info *info)
{
	t_node *tmp;

	printf("> a(%d): ", info->a.size);
	tmp = info->a.top;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n> b(%d): ", info->b.size);
	tmp = info->b.top;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

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

static int	find_pivots(t_stack *stack, int *p1, int *p2, int size)
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

void		sort_a(t_info *info, int size)
{
	int		i;
	int		p1;
	int		p2;
	t_sort	sort;

	if (size <= 1 || check_sorted_stack(&(info->a), 1, size))
		return ;
	else if (size == 2)
	{
		if (info->a.top->num > info->a.top->next->num)
			swap_sx(&(info->buf), &(info->a), SA);
		return ;
	}
	find_pivots(&(info->a), &p1, &p2, size);
	init_sort_info(&sort);
	i = 0;
	while (i < size)
	{
		if (info->a.top->num >= p2)
		{
			rotate_rx(&(info->buf), &(info->a), RA);
			(sort.ra_num)++;
		}
		else
		{
			push_pb(&(info->buf), &(info->a), &(info->b));
			(sort.pb_num)++;
			if (info->b.top && (info->b.top->num >= p1))
			{
				rotate_rx(&(info->buf), &(info->b), RB);
				(sort.rb_num)++;
			}
		}
		i++;
	}
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

void		sort_b(t_info *info, int size)
{
	int		i;
	int		p1;
	int		p2;
	t_sort	sort;

	if (size == 0)
		return ;
	if (size == 1)
	{
		push_pa(&(info->buf), &(info->a), &(info->b));
		return ;
	}
	else if (size == 2)
	{
		if (info->b.top->num < info->b.top->next->num)
			swap_sx(&(info->buf), &(info->b), SB);
		push_pa(&(info->buf), &(info->a), &(info->b));
		push_pa(&(info->buf), &(info->a), &(info->b));
		return ;
	}
	else if (check_sorted_stack(&(info->b), 0, size))
	{
		i = 0;
		while (i < size)
		{
			push_pa(&(info->buf), &(info->a), &(info->b));
			i++;
		}
		return ;
	}
	find_pivots(&(info->b), &p1, &p2, size);
	init_sort_info(&sort);
	i = 0;
	while (i < size)
	{
		if (info->b.top->num < p1)
		{
			rotate_rx(&(info->buf), &(info->b), RB);
			(sort.rb_num)++;
		}
		else
		{
			push_pa(&(info->buf), &(info->a), &(info->b));
			(sort.pa_num)++;
			if (info->a.top && (info->a.top->num < p2))
			{
				rotate_rx(&(info->buf), &(info->a), RA);
				(sort.ra_num)++;
			}
		}
		i++;
	}
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

int			solve(t_info *info)
{
	sort_a(info, info->a.size);
	return (1);
}
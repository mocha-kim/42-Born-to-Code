/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:47 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/13 15:00:35 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
*/

void	push_pa(t_stack *a, t_stack *b)
{
	t_node *node;

	if (b->size == 0)
		return ;
	node = b->top;
	if (b->size == 1)
		b->top = NULL;
	else
	{
		b->top = b->top->next;
		b->top->prev = NULL;
	}
	node->next = NULL;
	b->size--;
	if (a->size >= 1)
	{
		node->next = a->top;
		a->top->prev = node;
	}
	a->top = node;
	a->size++;
	write(1, "pa\n", 4);
}

void	push_pb(t_stack *a, t_stack *b)
{
	t_node *node;

	if (a->size == 0)
		return ;
	node = a->top;
	if (a->size == 1)
		a->top = NULL;
	else
	{
		a->top = a->top->next;
		a->top->prev = NULL;
	}
	node->next = NULL;
	a->size--;
	if (b->size >= 1)
	{
		node->next = b->top;
		b->top->prev = node;
	}
	b->top = node;
	b->size++;
	write(1, "pb\n", 4);
}
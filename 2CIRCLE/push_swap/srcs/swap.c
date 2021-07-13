/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/21 18:06:10 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/

int	sa(t_info *info)
{
	if (!info->a.head || !info->a.head->next)
		return (0);
	swap(info->a.head->num, info->a.head->next->num);
	if (ft_node_size(info->a.head) == 2)
		info->a.tail = ft_node_last(info->a.head);
	return (1);
}

/*
** sb : swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

int	sb(t_info *info)
{
	if (!info->b.head || !info->b.head->next)
		return (0);
	swap(info->b.head->num, info->b.head->next->num);
	if (ft_node_size(info->b.head) == 2)
		info->b.tail = ft_node_last(info->b.head);
	return (1);
}

/*
** ss : sa and sb at the same time.
*/

int	ss(t_info *info)
{
	if (sa(info) && sb(info))
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:40:41 by sunhkim           #+#    #+#             */
/*   Updated: 2021/05/21 18:02:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_list_size(t_node *node)
{
	size_t	ret;
	t_node	*tmp;

	ret = 0;
	tmp = node;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

void	ft_list_add_back(t_node **head, t_node *new_node)
{
	t_node	*tmp;

	if (!*head)
		ft_node_add_front(head, new_node);
	else
	{
		tmp = ft_node_last(*head);
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}

void	ft_list_add_front(t_node **head, t_node *new_node)
{
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}

t_node	*ft_node_last(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*ft_node_new(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

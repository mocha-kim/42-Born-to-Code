/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:59:07 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:09:12 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
t_list	*lst_add_back(t_list **list, char *line);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
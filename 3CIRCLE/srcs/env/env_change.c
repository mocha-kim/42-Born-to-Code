/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:38 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/09 15:53:24 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

extern t_state	g_state;

/*
** env_change
** Change environment variable values
** env: linked list, name: change target, content: Value to be changed
** return : 1: success change, 0: not exist env value
*/

int			env_change(char *name, char *content)
{
	t_env	*tmp;

	tmp = g_state.env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = content;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	find_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static int	change(t_env *tmp, char c, char *name, char *cont)
{
	if (tmp->content && c != 0)
		free(tmp->content);
	if (c != 0)
		tmp->content = cont;
	else
		free(cont);
	free(name);
	return (1);
}

int			env_change2(char *line)
{
	t_env	*tmp;
	int		i;
	char	*cont;
	char	*name;

	tmp = g_state.env;
	i = find_char(line);
	name = ft_strdup(line);
	name[i] = 0;
	cont = ft_substr(line + i + 1, 0, ft_strlen(line + i + 1));
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (change(tmp, line[i], name, cont));
		tmp = tmp->next;
	}
	free(cont);
	free(name);
	return (0);
}

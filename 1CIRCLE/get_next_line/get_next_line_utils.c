/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:31:15 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/14 16:47:17 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		has_newline(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join_save_buff(char *save, char *buff)
{
	int		i;
	int		j;
	int		savelen;
	int		bufflen;
	char	*result;

	savelen = ft_strlen(save);
	bufflen = ft_strlen(buff);
	if (!(result = (char *)malloc(sizeof(char) * (savelen + bufflen + 1))))
		return (0);
	i = 0;
	while (i < savelen)
	{
		result[i] = save[i];
		i++;
	}
	j = 0;
	while (j < bufflen)
	{
		result[i + j] = buff[j];
		j++;
	}
	result[i + j] = '\0';
	free(save);
	return (result);
}

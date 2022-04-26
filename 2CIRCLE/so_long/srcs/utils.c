/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:19:08 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 00:21:55 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_countc(char *str, char c)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		ft_findchar(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i] || s[i] == '\n')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(result))
		return (0);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len2 + len1 + 1);
	free(s1);
	free(s2);
	return (result);
}

void	ft_remove_newline(char **str)
{
	int	i;
	int	j;
	int length;
	char	*result;

	i = 0;
	length = ft_strlen(*str) - ft_countc(*str, '\n');
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return ;
	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if ((*str)[i] != '\n')
		{
			result[j] = (*str)[i];
			j++;
		}
		i++;
	}
	result[i] = '\0';
	free(*str);
	*str = result;
}
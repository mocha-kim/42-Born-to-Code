/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:48:28 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/27 16:57:58 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_word(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	while (s[i] != 0 && s[i] == c)
		i++;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] != 0 && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

void	find_next_str(char **str, int *len, char c)
{
	int		i;

	*str += *len;
	*len = 0;
	while (**str != 0 && **str == c)
		(*str)++;
	i = 0;
	while ((*str)[i] != 0)
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		substr_num;
	int		substr_len;
	char	**result;
	char	*substr;

	if (!s)
		return (NULL);
	substr_num = count_word(s, c);
	if (!(result = malloc(sizeof(char *) * (substr_num + 1))))
		return (NULL);
	i = 0;
	substr = (char *)s;
	substr_len = 0;
	while (i < substr_num)
	{
		find_next_str(&substr, &substr_len, c);
		if (!(result[i] = malloc(sizeof(char) * (substr_len + 1))))
			return (NULL);
		ft_strlcpy(result[i], substr, substr_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}

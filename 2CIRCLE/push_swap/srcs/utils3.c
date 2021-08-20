/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:24:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/08/20 16:48:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static unsigned int	count_word(const char *s, char c, unsigned int *substr_len)
{
	int		i;
	int		count;

	*substr_len = 0;
	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	find_next_str(char **str, unsigned int *len, char c)
{
	unsigned int	i;

	*str += *len;
	*len = 0;
	while (**str && **str == c)
		(*str)++;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static char	**freee(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i] != 0)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	srcsize;

	i = 0;
	srcsize = 0;
	while (src[i] != 0)
	{
		srcsize++;
		i++;
	}
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != 0 && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	substr_num;
	unsigned int	substr_len;
	char			**result;
	char			*substr;

	if (!s)
		return (NULL);
	substr_num = count_word(s, c, &substr_len);
	result = (char **)malloc(sizeof(char *) * (substr_num + 1));
	if (!result)
		return (NULL);
	i = 0;
	substr = (char *)s;
	while (i < substr_num)
	{
		find_next_str(&substr, &substr_len, c);
		result[i] = (char *)malloc(sizeof(char) * (substr_len + 1));
		if (!result[i])
			return (freee(result));
		ft_strlcpy(result[i], substr, substr_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}

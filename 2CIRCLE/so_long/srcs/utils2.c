/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:13:53 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 16:15:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*result;

	if (!str || !(result = malloc(sizeof(char) * len + 1)))
		return (0);
	if (start >= ft_strlen(str))
	{
		*result = 0;
		return (result);
	}
	ft_strlcpy(result, str + start, len + 1);
	return (result);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (0);
	i = 0;
	while (i < size)
		str[i++] = *s1++;
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len2 + len1 + 1);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && j < dstsize - dst_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (src_len + dst_len);
}

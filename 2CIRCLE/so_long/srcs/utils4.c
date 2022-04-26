/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:51:33 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/08 00:28:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strdup_free(char *s)
{
	char	*new;
	int		size;
	int		i;

	new = NULL;
	size = ft_strlen(s);
	i = 0;
	new = malloc(size + 1);
	if (!(new))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strlcpy_free(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	new = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_free(s2));
	else if (s2 == NULL)
		return (ft_strdup_free(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc(s1_len + s2_len);
	if (!(new))
		return (NULL);
	ft_strlcpy_free(new, s1, s1_len + 1);
	ft_strlcpy_free(new + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new);
}
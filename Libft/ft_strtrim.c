/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:20:34 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/24 21:11:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const set)
{
	unsigned int	i;
	unsigned int	t_start;
	unsigned int	t_len;
	char			*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != 0 && ft_strchr(set, *s1))
		i++;
	t_start = i;
	t_len = ft_strlen(s1);
	while (t_len > 0 && ft_strchr(set, s1[t_len]))
		t_len--;
	result = ft_substr((char *)s1, t_start, t_len + 1);
	return (result);
}

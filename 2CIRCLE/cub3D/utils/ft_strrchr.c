/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:49:24 by sunhkim           #+#    #+#             */
/*   Updated: 2021/04/28 20:49:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strrchr(char *s, int c)
{
	int	size;

	size = ft_strlen(s) + 1;
	while (size--)
	{
		if (s[size] == (char)c)
			return ((char*)(s + size));
	}
	return (NULL);
}

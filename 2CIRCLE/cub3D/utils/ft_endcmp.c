/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:49:05 by sunhkim           #+#    #+#             */
/*   Updated: 2021/04/28 20:49:07 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_endcmp(char *str, char *s)
{
	int size;
	int	i;

	size = ft_strlen(str) - 1;
	i = ft_strlen(s) - 1;
	while (i >= 0 && size >= 0)
	{
		if (str[size--] != s[i--])
			return (0);
	}
	return (1);
}

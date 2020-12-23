/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:15:15 by sunhkim           #+#    #+#             */
/*   Updated: 2020/12/23 17:26:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	i = 0;
	dst_tmp = dst;
	src_tmp = src;
	while (i < n)
	{
		if (src_tmp[i] == c)
			break ;
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	if (i == n)
		return (0);
	else
		return (&dst[i]);
}

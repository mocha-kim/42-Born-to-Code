/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:53:43 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/27 19:36:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_pointer(unsigned long address, t_flags *flags)
{
	int		result;
	
	address = 0;
	result = flags->width;
	return (result);
}

int		print_ocint(unsigned int num, t_flags *flags)
{
	int		result;

	num = 0;
	result = flags->width;
	return (result);
}

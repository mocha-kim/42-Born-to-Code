/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:53:31 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/28 21:26:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_int(int num, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*tmpstr;
	char	*blanks;

	tmpstr = ft_itoa(num);
	strlen = ft_strlen(tmpstr);
	if (strlen < flags->dot)
		add_prec(&tmpstr, &strlen, flags);
	blanks = get_blanks(strlen, flags);
	result = print_buffer(tmpstr, blanks, flags);
	free(tmpstr);
	free(blanks);
	return (result);
}

int		printd_uint(unsigned int num, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*tmpstr;
	char	*blanks;

	tmpstr = ft_utoa(num);
	strlen = ft_strlen(tmpstr);
	if (strlen < flags->dot)
		add_prec(&tmpstr, &strlen, flags);
	blanks = get_blanks(strlen, flags);
	result = print_buffer(tmpstr, blanks, flags);
	free(tmpstr);
	free(blanks);
	return (result);
}

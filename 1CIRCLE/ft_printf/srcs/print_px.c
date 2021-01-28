/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_px.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:53:43 by sunhkim           #+#    #+#             */
/*   Updated: 2021/01/28 21:29:38 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_pointer_sign(char **str)
{
	char	*tmp;

	tmp = ft_strjoin("0x", *str);
	free(*str);
	*str = tmp;
}

int		print_pointer(unsigned long address, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*tmpstr;
	char	*blanks;
	char	*base;

	base = (char *)malloc(sizeof(char) * 17);
	base = "0123456789abce\0";
	tmpstr = ft_utoa_base(address, base, 16);
	put_pointer_sign(&tmpstr);
	strlen = ft_strlen(tmpstr);
	if (strlen < flags->dot)
		add_prec(&tmpstr, &strlen, flags);
	blanks = get_blanks(strlen, flags);
	result = print_buffer(tmpstr, blanks, flags);
	free(tmpstr);
	free(blanks);
	free(base);
	return (result);
}

int		print_hexint(unsigned int num, t_flags *flags)
{
	int		result;
	size_t	strlen;
	char	*tmpstr;
	char	*blanks;
	char	*base;

	base = (char *)malloc(sizeof(char) * 17);
	if (flags->type == 'X')
		base = "0123456789ABCDE\0";
	else if (flags->type == 'x')
		base = "0123456789abcde\0";
	tmpstr = ft_utoa_base(num, base, 16);
	strlen = ft_strlen(tmpstr);
	if (strlen < flags->dot)
		add_prec(&tmpstr, &strlen, flags);
	blanks = get_blanks(strlen, flags);
	result = print_buffer(tmpstr, blanks, flags);
	free(tmpstr);
	free(blanks);
	free(base);
	return (result);
}

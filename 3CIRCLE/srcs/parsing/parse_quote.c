/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:20:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/14 18:01:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

/*
** closed==true, opened==flase
*/

void		count_quote(char *line, int *double_quote, int *single_quote, int i)
{
	if (*double_quote)
	{
		if (is_quote(line, i) == DOUBLE_QUOTE)
			*double_quote = FALSE;
	}
	else if (*single_quote)
	{
		if (is_quote(line, i) == SINGLE_QUOTE)
			*single_quote = FALSE;
	}
	else
	{
		if (is_quote(line, i) == DOUBLE_QUOTE)
			*double_quote = TRUE;
		if (is_quote(line, i) == SINGLE_QUOTE)
			*single_quote = TRUE;
	}
}

/*
** check single, double auotes are closed
** return 1:closed 0:opened(error) -1:empty line
*/

int			check_quote_closed(char *line)
{
	int		i;
	int		double_quote;
	int		single_quote;

	i = 0;
	double_quote = FALSE;
	single_quote = FALSE;
	if (!line)
		return (-1);
	while (line[i])
	{
		count_quote(line, &double_quote, &single_quote, i);
		i++;
	}
	return (!(double_quote || single_quote));
}

/*
** check single, double quotes before parsing
** return 0:failed 1:succeed 127:exit
*/

int			check_quote(char **line)
{
	if (!check_quote_closed(*line))
	{
		ft_strdel(line);
		return (print_syntax_error(ERR_QUOTE));
	}
	return (1);
}

/*
** delete outer quotes
** return 0:not found 1:succeed 127:exit
*/

static int	del_quote2(char **content, int *i)
{
	int		j;
	char	*str;

	j = *i + 1;
	while ((*content)[j])
	{
		if ((*content)[*i] == (*content)[j] && (is_quote(*content, j) != 0))
		{
			if (!(str = split_and_join(*content, *i, j)))
				return (print_memory_error(ERR_MALLOC));
			free(*content);
			*content = str;
			(*i) += j - *i - 2;
			return (1);
		}
		j++;
	}
	return (0);
}

/*
** delete outer quotes
** return 0:null 1:succeed 127:exit
*/

int			del_quote(t_dlist **parse)
{
	int		i;
	t_dlist	*tmp;

	tmp = *parse;
	while (tmp)
	{
		i = 0;
		while (((char *)(tmp->content))[i])
		{
			if ((is_quote((char *)(tmp->content), i) != 0))
			{
				if (del_quote2((char **)(&(tmp->content)), &i) == EXIT_CODE)
					return (EXIT_CODE);
			}
			if (((char *)(tmp->content))[i] == '\0')
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

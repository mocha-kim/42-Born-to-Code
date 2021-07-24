/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:25:29 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/23 16:23:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

extern t_state	g_state;

void		find_env(char **line)
{
	int		i;
	int		j;
	char	*env;

	i = -1;
	while (++i < (int)ft_strlen(*line))
	{
		if ((*line)[i] == '$')
		{
			j = i + 1;
			while (j < (int)ft_strlen(*line) && (*line)[j] != ' '
			&& (*line)[j] != '$' && (*line)[j] != ';' && (*line)[j] != '\"'
			&& (*line)[j] != '\'')
				j++;
			if (j == i + 1)
				continue ;
			env = ft_substr(*line, i + 1, j - i - 1);
			replace_env(line, i, j - 1, env_search(env));
			free(env);
			i = j - 1;
		}
	}
}

static void	input_read(int fd, char *eof)
{
	char	*line;

	while (1)
	{
		if (!(line = readline("> ")))
		{
			if (g_state.is_here <= 1)
				ft_putstr_fd("\b\b  \b\b", STD_OUT);
			break ;
		}
		g_state.is_here = TRUE;
		if (!ft_strcmp(line, eof))
		{
			ft_strdel(&line);
			break ;
		}
		find_env(&line);
		ft_putendl_fd(line, fd);
		ft_strdel(&line);
	}
	close(fd);
}

void		read_line(int fd, char *eof)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		input_read(fd, eof);
		exit(g_state.ret);
	}
	else
	{
		g_state.is_fork = TRUE;
		close(fd);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_state.ret = WEXITSTATUS(status);
		g_state.is_fork = FALSE;
	}
}

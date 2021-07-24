/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:27 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:35:28 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

/*
** pip[0] : read file descriptor
** pip[1] : write file descriptor
*/

void		set_pipe(t_dlist *info)
{
	t_program	*cmd;

	cmd = info->content;
	if (cmd->flag == F_PIPE || (info->prev
		&& ((t_program*)info->prev->content)->flag == F_PIPE))
	{
		if (cmd->flag == F_PIPE)
			dup2(cmd->pip[1], 1);
		if (info->prev && ((t_program*)info->prev->content)->flag == F_PIPE)
			dup2(((t_program*)info->prev->content)->pip[0], 0);
	}
}

void		close_fd(t_dlist *info, int in, int out)
{
	t_program	*cmd;
	t_program	*prev;

	cmd = info->content;
	if (info->prev)
	{
		prev = info->prev->content;
		close(prev->pip[0]);
	}
	close(cmd->pip[1]);
	if (cmd->flag != F_PIPE)
		close(cmd->pip[0]);
	if (cmd->fd[0] != 0)
		close(cmd->fd[0]);
	if (cmd->fd[1] != 1)
		close(cmd->fd[1]);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:16:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/09 14:56:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERR_ARG 0
# define ERR_MEM 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/errno.h>

typedef struct s_info
{
	int	num;
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
	pthread_mutex_t		m_write;
	pthread_mutex_t		*m_fork;
}	t_info;

typedef struct s_philo
{
	int	id;
	pthread_t				t_id;
	pthread_mutex_t			*fork_r;
	pthread_mutex_t			*fork_l;
}	t_philo;

/*
** philosophers.c
*/

int		philosophers(t_info *info, t_philo **philos);

/*
** parse.c
*/

int	parse_args(t_info *info, int argc, char *argv[]);

/*
** utils.c
*/

int		print_err(int error);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_atoi(const char *str);

#endif
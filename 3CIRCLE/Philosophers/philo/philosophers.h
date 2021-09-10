/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:16:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/10 15:42:38 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERR_ARG 0
# define ERR_MEM 1
# define ERR_PTH 2

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>

typedef struct s_info
{
	int					num;
	int					die;
	int					eat;
	int					sleep;
	int					must_eat;
	int					has_6th_arg;
	int					sig;
	pthread_mutex_t		m_write;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_forks[200];
}	t_info;

typedef struct s_philo
{
	int					id;
	int					num_eat;
	long unsigned int	time_hunger;
	pthread_t			t_id;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		*fork_l;
	t_info				*info;
}	t_philo;

/*
** philosophers.c
*/

int		philosophers(t_info *info, t_philo **philos);

/*
** parse.c
*/

int		parse_args(t_info *info, int argc, char *argv[]);

/*
** threads.c
*/

void	*thread(void *data);

/*
** utils.c
*/

int		print_err(int error);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_atoi(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:16:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/13 20:04:26 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERR_ARG 0
# define ERR_MEM 1
# define ERR_PTH 2
# define ERR_PMU 3

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
	long int			time_start;
	pthread_mutex_t		m_write;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_forks[200];
}	t_info;

typedef struct s_philo
{
	int					id;
	int					num_eat;
	long int			time_hunger;
	pthread_t			t_id;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		eating;
	t_info				*info;
}	t_philo;

/*
** philosophers.c
*/

int			philosophers(t_info *info, t_philo **philos);

/*
** init.c
*/

void		init_info(t_info *info);
int			init_info_mutex(t_info *info);
void		init_philos(t_info *info, t_philo **philos);
void		init_philos_mutex(t_info *info, t_philo **philos);

/*
** parse.c
*/

int			parse_args(t_info *info, int argc, char *argv[]);

/*
** threads.c
*/

void		*thread(void *data);

/*
** timer.c
*/

void		sleep_time(t_info *info, long int time);
long int	get_time(t_info *info);

/*
** utils.c
*/

int			print_err(int error);
void		print_state(t_info *info, t_philo *philo, char *str, int *sig);
int			ft_isdigit(int c);
int			ft_isnum(char *str);
int			ft_atoi(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:16:17 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/08 19:08:25 by sunhkim          ###   ########.fr       */
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
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_info;

typedef struct s_philo
{
	int					id;
}	t_philo;

/*
** philosophers.c
*/


/*
** utils.c
*/


#endif
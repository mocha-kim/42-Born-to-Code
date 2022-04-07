/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:20:50 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/07 16:16:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
// # include <limits.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
int	ft_endcmp(char *str, char *s);
int	ft_findchar(char *s);
int	ft_print_error(char *description);

char	*ft_substr(char *str, int start, int len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

#endif
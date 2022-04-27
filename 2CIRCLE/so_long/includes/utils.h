/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:20:50 by sunhkim           #+#    #+#             */
/*   Updated: 2022/04/27 00:41:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_countc(char *str, char c);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_remove_newline(char **str);

int		ft_strlen_without_nl(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_print_error(char *str);
int		check_file_name(char *path);

#endif
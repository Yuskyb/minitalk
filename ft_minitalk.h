/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:52:45 by yususato          #+#    #+#             */
/*   Updated: 2023/10/02 16:51:41 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <signal.h>

int			ft_putnbr_i(int nb);
int			ft_putnbr_u(unsigned int nb);
int			ft_putstr(char *s);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *fmt, ...);
int			count(const char *save, va_list ap);
int			ft_range(int c, va_list ap);
int			ft_process_u(unsigned int u);
int			ft_process_c(char c);
int			ft_process_i(int c);
int			ft_process_s(char *c);
int			ft_process_x(unsigned int p, int c);
int			ft_small(unsigned int p);
int			ft_large(unsigned int p);
int			ft_process_p(uintptr_t p);
int			ft_putchar(int n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check(int i);
int			ft_atoi(const char *str);
static int	space(const char *str);

#endif
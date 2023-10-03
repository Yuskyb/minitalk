/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:36:41 by yususato          #+#    #+#             */
/*   Updated: 2023/10/02 16:45:24 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 0;
	while (digit <= 7)
	{
		if (c & (1 << digit))
		{
			usleep(800);
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("error");
				exit(1);
			}
		}
		else
		{
			usleep(800);
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("error");
				exit(1);
			}
		}
		digit++;
	}
}

void	my_send(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (ft_printf("error"));
	my_send(pid, argv[2]);
}

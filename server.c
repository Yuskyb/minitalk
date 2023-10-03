/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:36:47 by yususato          #+#    #+#             */
/*   Updated: 2023/10/02 16:32:14 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	signalhandler(int signal)
{
	static int	i = 0;
	static char	message = 0;

	if (signal == SIGUSR1)
	{
		message |= (1 << i);
	}
	else if (signal == SIGUSR2)
		;
	else
	{
		ft_printf("SIGNAL");
		exit(1);
	}
	i++;
	if (i == 8)
	{
		write(1, &message, 1);
		message = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("%d", getpid());
	if (signal(SIGUSR1, signalhandler) == -1)
	{
		ft_printf("error");
		return (1);
	}
	if (signal(SIGUSR2, signalhandler) == -1)
	{
		ft_printf("error");
		return (1);
	}
	while (1)
		pause();
}

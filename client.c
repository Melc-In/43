/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:05 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 10:14:16 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char *message)
{
	int	i;
	int	bit;

	bit = 32;
	i = -1;
	while (bit--)
	{
		if ((ft_strlen(message) >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
	while (message[++i])
	{
		bit = 8;
		while (bit--)
		{
			if ((message[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (argc != 3)
		return (1);
	if (!ft_strlen(argv[2]))
		return (1);
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid < 1)
			return (1);
		send_message(pid, argv[2]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:05 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 06:15:15 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_byte(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

static void	send_len_mess(int pid, int len)
{
	int	bit;

	bit = 32;
	while (bit--)
	{
		if ((len >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (argc > 3)
		return (1);
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		if (pid < 1)
			return (1);
		send_len_mess(pid, ft_strlen(argv[2]));
		send_byte(pid, '\n');
		while (!argv[2][i])
		{
			send_byte(pid, argv[2][i]);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

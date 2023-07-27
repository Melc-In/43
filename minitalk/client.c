/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:05 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/26 22:51:48 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	send_len_mess(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit <= 31)
	{
		if ((len >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	len_mess;

	i = 0;
	pid = atoi(argv[1]);
	len_mess = ft_strlen(argv[2]);
	if (argc > 3)
		return (1);
	if (pid < 1)
		return (1);
	if (argc == 3)
	{
		send_len_mess(pid, len_mess);
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

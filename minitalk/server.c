/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 20:56:21 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	read_len(int *len_mess, char **message, unsigned int *byte)
{
	*len_mess = *byte + 1;
	*message = ft_calloc(*len_mess, 1);
	if (*message == NULL)
		ft_putstr_fd("malloc failed", 2);
	*byte = 0;
}

static void	s_handler(int signum)
{
	static t_msg	msg = {0};

	msg.byte <<= 1;
	msg.byte |= (signum == SIGUSR1);
	msg.bit_len++;
	if (msg.bit_len == 32)
		read_len(&msg.len_mess, &msg.message, &msg.byte);
	if (msg.bit_len > 32)
		msg.bit++;
	if (msg.bit == 8)
	{
		msg.message[msg.i] = msg.byte;
		msg.i++;
		if (msg.byte == 0)
		{
			ft_putstr_fd(msg.message, 1);
			free(msg.message);
			msg.bit_len = 0;
			msg.i = 0;
		}
		msg.byte = 0;
		msg.bit = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, s_handler);
		signal(SIGUSR2, s_handler);
		pause();
	}
	return (0);
}

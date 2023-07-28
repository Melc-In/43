/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 09:12:12 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	s_handler(int signum)
{
	static char	*message;
	static int	len_mess = 0;
	static int	bit_len = 0;
	static int	byte = 0;
	static int	bit = 0;
	static int	i = 0;

	byte <<= 1;
	byte |= (signum == SIGUSR1);
	bit_len++;
	if (bit_len == 31)
	{
		len_mess = byte;
		message = ft_calloc(len_mess + 1, 1);
		byte = 0;
	}
	if (bit_len > 31)
		bit++;
	if (bit == 7)
	{
		message[i] = byte;
		i++;
		if (byte == '\0')
		{
			ft_putstr_fd(message, 1);
			free(message);
			bit_len = 0;
			len_mess = 0;
			i = 0;
		}
		byte = 0;
		bit = 0;
	}
}

//static void	s_handler(int signum)
//{
//	static t_msg	msg = {0};
//}

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

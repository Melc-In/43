/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 07:24:11 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_len_mess(int signum)
{
	static int	byte_len = 0;
	static int	bit_len = 0;

	byte_len <<= 1;
	byte_len |= (signum == SIGUSR1);
	bit_len++;
	if (bit_len == 31)
		return (byte_len);
	return (0);
}

static void	s_handler(int signum)
{
	static char	*message;
	static int	len_mess;
	static int	byte = 0;
	static int	bit = 0;
	static int	i = 0;

	if (bit <= 31)
	{
		len_mess = get_len_mess(signum);
		if (len_mess != 0)
			message = ft_calloc(len_mess + 1, 1);
	}
	if (bit >= 32)
	{
		byte <<= 1;
		byte |= (signum == SIGUSR1);
	}
	if (bit == 40)
	{
		if (byte == '\0')
			ft_putstr_fd(message, 1);
		message[i] = byte;
		byte = 0;
		bit = 32;
		i++;
	}
	bit++;
}

//static void	s_handler(int signum)
//{
//	static t_msg	msg = {0};
//}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, s_handler);
		signal(SIGUSR2, s_handler);
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/27 08:12:02 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_len_mess(int signum)
{
	static int byte_len;
	static int bit_len;

	bit_len++;
	if (bit_len == 31)
	{
		byte_len <<= 1;
		byte_len |= (signum == SIGUSR1);
		return (byte_len);
	}
	return (bit_len);
}

void	s_handler(int signum)
{
	static char	*message;
	static size_t	len_mess;
	static int	byte = 0;
	static int	bit = 0;
	static int	i = 0;

	bit++;
	if (ft_strlen(message) == len_mess)
	{
		ft_putstr_fd(message, 1);
		bit = 42;
	}
	if (bit <= 31)
	{
		len_mess = get_len_mess(signum);
		message = ft_calloc(len_mess, 1);
		bit++;
	}
	if (bit == 40)
	{
		byte <<= 1;
		byte |= (signum == SIGUSR1);
		message[i] = byte;
		byte = 0;
		bit = 32;
		i++;
	}
}

int	main()
{
	ft_putnbr_fd(getpid(), 1);
	while (1)
	{
		signal(SIGUSR1, &s_handler);
		signal(SIGUSR2, &s_handler);
		pause();
	}
	return (0);
}

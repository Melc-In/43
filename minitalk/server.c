/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 02:54:53 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_len_mess(int signum)
{
	static int byte_len = 0;
	static int bit_len = 0;

	bit_len++;
	byte_len <<= 1;
	byte_len |= (signum == SIGUSR1);
	if (bit_len == 31)
		return (byte_len);
	return (0);
}

void	s_handler(int signum)
{
	static char	*message;
	static size_t	len_mess;
	static int	byte = 0;
	static int	bit = 0;
	static int	i = 0;

	bit++;
	if (bit <= 31)
	{
		len_mess = get_len_mess(signum);
		ft_putnbr_fd(len_mess, 1);
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

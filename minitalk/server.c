/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/21 03:08:48 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_handler(int signum)
{
	static int	bit;

	bit = 0;
	if (signum == SIGUSR1);
		
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

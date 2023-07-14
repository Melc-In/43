/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/14 00:31:20 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	ft_putnbr_fd(get_pid(), 1);
}

int	main(int argc, char **argv)
{
	print_pid();
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &;
	while (1)
		usleep(1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:53:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/16 19:12:01 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd2(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	long long	nb;
	int			len;

	nb = n;
	len = 0;
	if (n < 0)
		len++;
	ft_putnbr_fd2(n, fd);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

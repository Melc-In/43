/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:53:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/08 04:29:30 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	rest;
	int	entire;
	int	frbd;

	frbd = n == -2147483648;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		if (frbd)
			n += 1;
		n *= -1;
	}
	rest = n % 10;
	entire = n / 10;
	if (n > 9)
		ft_putnbr_fd(entire, fd);
	if (frbd)
		rest++;
	ft_putchar_fd(rest + '0', fd);
}

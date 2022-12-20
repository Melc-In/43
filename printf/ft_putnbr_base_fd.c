/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:02 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/20 18:58:35 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putnbr_base_fd2(unsigned long long nbr, char *base, int fd)
{
	if (nbr > ft_strlen(base) - 1)
		ft_putnbr_base_fd2(nbr / ft_strlen(base), base, fd);
	write(1, &base[nbr % ft_strlen(base)], 1);
}

int	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd)
{
	int	count;

	count = 1;
	ft_putnbr_base_fd2(nbr, base, fd);
	while (nbr > ft_strlen(base) - 1)
	{
		count++;
		nbr /= ft_strlen(base);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:02 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 20:53:15 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

static int	ft_check_base(char *base)
{
	int	blen;
	int	i;
	int	j;

	blen = ft_strlen2(base);
	if (blen <= 1)
		return (0);
	i = 0;
	while (i < blen)
	{	
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (j < blen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	putnbr_base_fd(int nbr, char *base, int fd)
{
	int		quotient;
	int		remainder;
	long	long_nbr;
	int		blen;

	long_nbr = nbr;
	blen = ft_strlen2(base);
	if (!ft_check_base(base))
		return ;
	if (long_nbr < 0)
	{
		ft_putchar_fd('-', fd);
		long_nbr *= -1;
	}
	remainder = long_nbr % blen;
	quotient = long_nbr / blen;
	if (long_nbr > blen - 1)
		ft_putnbr_base_fd(quotient, base, fd);
	ft_putchar_fd(base[remainder], fd);
}

int	ft_putnbr_base_fd(int nbr, char *base, unsigned long long fd)
{
	unsigned long long	long_nbr;
	int		blen;
	int		len;

	putnbr_base_fd(nbr, base, fd);
	long_nbr = nbr;
	blen = ft_strlen(base);
	len = 0;
	if (!check_base(base))
		return (len);
	if (long_nbr < 0)
	{
		len++;
		long_nbr *= -1;
	}
	while (long_nbr > blen - 1)
	{
		long_nbr /= blen;
		len++;
	}
	len++;
	return (len);
}

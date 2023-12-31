/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:52:48 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/31 16:42:48 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_digit(int n)
{
	int	n2;
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n2 = n * -1;
		nb++;
	}
	else
		n2 = n;
	while (n2 / 10 > 0)
	{
		n2 /= 10;
		nb++;
	}
	return (nb);
}

static int	negative_modulo(int n)
{
	if (n == -2147483648)
		return (8);
	if (n < 0)
		n *= -1;
	return (n % 10);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	i = nb_digit(n);
	result = ft_calloc(i + 2, 1);
	if (!result)
		return (NULL);
	if (n == 0)
	{
		result[i] = '0';
		return (result);
	}
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		result[i] = '0' + negative_modulo(n);
		n /= 10;
		i--;
	}
	return (result);
}

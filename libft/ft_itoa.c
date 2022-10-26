/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:52:48 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/26 15:39:56 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	nb_digit(int n)
{
	int	n2;
	int	nb;

	n2 = n;
	nb = 0;
	while (n2 / 10 > 1)
	{
		n_cpy /= 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_cpy;
	int		sign;

	sign = 0;
	n_cpy = n;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	if (sign)
	{
		result = malloc(sign + nb_digit(n));
		result[0] = '-';
	}
	else
		result = malloc(nb_digit(n) * sizeof(char));
	while (n_cpy / 10 > 0)
	{
		*result = (n_cpy % 10) + '0';
		result++;
		n_cpy /= 10;
	}
	result = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:08:03 by cglandus          #+#    #+#             */
/*   Updated: 2022/09/30 17:23:26 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (!ft_isprint(str[i]))
		i++;
	if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
		return (0);
	if (str[i] == '-')
		sign = -1;
	while (!ft_isdigit(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		result += str[i] - '0';
		if (ft_isdigit(str[i]))
			result *= 10;
		i++;
	}
	return (result * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:40 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/01 08:58:50 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int				i;
	int				sign;
	long			result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32
		|| (str[i] == '0' && (str[i + 1] >= '0'
				&& str[i + 1] <= '9')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 2147483647 && sign != -1)
		return (2147483648);
	return (result * sign);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

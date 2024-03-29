/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:33:12 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/04 00:32:41 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN
		|| ft_atoi(str) == 2147483648)
		return (0);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	in_stack(t_stack stack, size_t filled, long n)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		if (stack.nums[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack stack)
{
	size_t	i;

	i = 0;
	if (stack.size == 0)
		return (0);
	while (i < stack.size - 1)
	{
		if (stack.nums[i] < stack.nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	contains_number(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

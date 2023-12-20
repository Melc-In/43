/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:33:12 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/20 00:15:50 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	in_stack(t_stack *stack, int n)
{
	size_t	i;

	i = 0;
	while (i < stack->filled)
	{
		if (stack->nums[i] == n)
			return (1);
		i++;
	}
	return (0);
}

size_t	size_stack(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_sorted(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < stack->size)
	{
		while (j < stack->size)
		{
			if (!(stack->nums[i] > stack->nums[j]))
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

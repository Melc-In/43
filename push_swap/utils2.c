/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:00:59 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/01 23:04:28 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_max(t_stack stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack.size)
	{
		if (stack.nums[i] < stack.nums[j])
			i = j;
		j++;
	}
	return (i);
}

size_t	get_min(t_stack stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack.size)
	{
		if (stack.nums[i] > stack.nums[j])
			i = j;
		j++;
	}
	return (i);
}

size_t	size_stack(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

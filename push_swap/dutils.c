/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:19:46 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/12 03:28:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_min(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack->size)
	{
		if (stack->nums[i] > stack->nums[j])
			i = j;	
		j++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:50:13 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/09 01:57:32 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, char *mess)
{
	swap(a, mess);
	swap(b, mess);
}

void	rr(t_stack *a, t_stack *b, char *mess)
{
	rotate(a, mess);
	rotate(b, mess);
}

void	rrab(t_stack *stack, char *mess)
{
	size_t	i;
	size_t	j;
	int		stash;
	int		last;

	i = 0;
	j = 1;
	last = stack->nums[0];
	while (i < stack->size && j < stack->size)
	{
		stash = stack->nums[j];
		stack->nums[j] = stack->nums[i];
		stack->nums[i] = stash;
		i++;
		j++;
	}
	stack->nums[stack->size - 1] = last;
	ft_putstr_fd(mess, 1);
}

void	rrr(t_stack *a, t_stack *b, char *mess)
{
	rrab(a, mess);
	rrab(b, mess);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:25 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/31 17:10:24 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop(t_stack *a)
{
	int	top;

	if (a->size == 0)
		return (0);
	top = a->nums[a->size - 1];
	a->size--;
	a->filled--;
	return (top);
}

void	swap(t_stack *stack, char *mess)
{
	int	temp;

	temp = stack->nums[stack->size - 1];
	stack->nums[stack->size - 1] = stack->nums[stack->size - 2];
	stack->nums[stack->size - 2] = temp;
	ft_putstr_fd(mess, 1);
}

void	push(t_stack *s1, t_stack *s2, char *mess)
{
	int	n;

	n = pop(s1);
	s2->size++;
	s2->nums[s2->size - 1] = n;
	ft_putstr_fd(mess, 1);
}

void	rotate(t_stack *stack, char *mess)
{
	size_t	i;
	size_t	j;
	int		stash;
	int		top;

	if (stack->filled > 0)
	{
		i = stack->size;
		j = i - 2;
		top = stack->nums[i - 1];
		while (i > 0)
		{
			stash = stack->nums[j];
			stack->nums[j] = stack->nums[i - 1];
			stack->nums[i - 1] = stash;
			i--;
			j--;
		}
		stack->nums[0] = top;
		ft_putstr_fd(mess, 1);
	}
}

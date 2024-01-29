/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:25 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/30 00:10:06 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *mess)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->nums[stack->size - 1];
	stack->nums[stack->size - 1] = stack->nums[stack->size - 2];
	stack->nums[stack->size - 2] = temp;
	ft_putstr_fd(mess, 1);
}

void	push(t_stack *s1, t_stack *s2, char *mess)
{
	int	top;

	if (s1->size == 0)
		return ;
	top = s1->nums[s1->size - 1];
	s1->size--;
	s2->size++;
	s2->nums[s2->size - 1] = top;
	ft_putstr_fd(mess, 1);
}

void	rotate(t_stack *stack, char *mess)
{
	size_t	i;
	size_t	j;
	int		stash;
	int		top;

	if (stack->size > 0)
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
			if (j == 0)
				break ;
			j--;
		}
		stack->nums[0] = top;
		ft_putstr_fd(mess, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:19:46 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/31 19:28:05 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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

static size_t	chunk_switch(size_t size)
{
	if (size <= 100)
		return (5);
	if (size <= 500)
		return (9);
	if (size > 500)
		return (12);
	return (5);
}

size_t	to_push(t_stack s, size_t min, size_t max)
{
	size_t	i;

	i = s.size - 1;
	while (i >= 0)
	{
		if ((size_t)s.nums[i] >= min && (size_t)s.nums[i] <= max)
			return (i);
		i--;
	}
	return (i);
}

static void	push_chunk(t_stack *a, t_stack *b, size_t chunk_size, size_t i)
{
	while (b->size != (i + 1) * chunk_size && a->size > 0)
	{
		if (i * chunk_size <= (size_t)a->nums[a->size - 1]
			&& (size_t)a->nums[a->size - 1] <= (i + 1) * chunk_size)
		{
			if ((size_t)a->nums[a->size - 1] >= chunk_size * (i + 1) / 2)
				push(a, b, "pb\n");
			else
			{
				push(a, b, "pb\n");
				rrab(b, "rrb\n");
			}
		}
		else if (to_push(*a, chunk_size * i, chunk_size * (i + 1))
				>= a->size / 2)
			rotate(a, "ra\n");
		else
			rrab(a, "rra\n");
	}
}

void	butterfly_sort(t_stack *a, t_stack *b)
{
	size_t	chunk_size;
	size_t	i;

	chunk_size = a->size / chunk_switch(a->size);
	i = 0;
	normalize_stack(a);
	while (a->size)
	{
		push_chunk(a, b, chunk_size, i);
		i++;
	}
	while (b->size)
	{
		while (get_max(*b) != b->size - 1)
		{
			if (get_max(*b) >= b->size / 2)
				rotate(b, "rb\n");
			else
				rrab(b, "rrb\n");
		}
		push(b, a, "pa\n");
	}
}

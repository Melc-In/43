/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:58:04 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/31 13:54:18 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	under6_handler(t_stack *a, t_stack *b)
{
	b->filled++;
	if (a->size == 2)
	{
		if (!is_sorted(a))
			swap(a, "sa\n");
	}
	/*
	if (a->size == 3)
	{	
    }*/
}

void	switch_algo(t_stack *a)
{
	t_stack	b;

	b.nums = ft_calloc(a->size, sizeof(int));
	b.size = a->size;
	b.filled = 0;
	if (a->size < 7 && a->size != 0)
	{
		under6_handler(a, &b);
	}
	else if (a->size > 6 && a-> size != 0)
	{
		//butterfly_sort(a, b)
	}
	free(b.nums);
}
/*static void normalize_stack(t_stack *a)
{
}

static void    butterfly_sort(t_stack *a, t_stack *b)
{
    normalize_stack(a);
}*/

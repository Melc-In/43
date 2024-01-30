/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:58:04 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/30 22:46:58 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_3(t_stack *a, size_t max)
{
	if ((max == a->size - 1) && (a->nums[0] > a->nums[1]))
		rotate(a, "ra\n");
	else if ((max == a->size -1) && (a->nums[0] < a->nums[1]))
	{
		rotate(a, "ra\n");
		swap(a, "sa\n");
	}
	else if ((max == 1) && (a->nums[0] > a->nums[a->size - 1]))
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else if ((max == 1) && (a->nums[0] < a->nums[a->size -1]))
		rrab(a, "rra\n");
	else if ((max == 0) && (a->nums[a->size - 1] > a->nums[1]))
		swap(a, "sa\n");
}

static void	handle_4(t_stack *a, t_stack *b, size_t min)
{
	if (min == a->size - 1)
		push(a, b, "pb\n");
	else if (min == 2)
	{
		rotate(a, "ra\n");
		push(a, b, "pb\n");
	}
	else if (min == 1)
	{
		rotate(a, "ra\n");
		rotate(a, "ra\n");
		push(a, b, "pb\n");
	}
	else if (min == 0)
	{
		rrab(a, "rra\n");
		push(a, b, "pb\n");
	}
	handle_3(a, get_max(*a));
	push(b, a, "pa\n");
}

static void	under6_handler(t_stack *a, t_stack *b)
{
	if (a->size == 2 || a->size == 1)
	{
		if (!is_sorted(*a))
			swap(a, "sa\n");
		return ;
	}
	if (a->size == 3)
		handle_3(a, get_max(*a));
	else if (a->size == 4)
		handle_4(a, b, get_min(*a));
	else if (a->size == 5)
	{
		while (get_min(*a) != 4)
			rotate(a, "ra\n");
		push(a, b, "pb\n");
		handle_4(a, b, get_min(*a));
		push(b, a, "pa\n");
	}
}

void	switch_algo(t_stack *a)
{
	t_stack	b;

	b.nums = ft_calloc(a->size, sizeof(int));
	b.size = 0;
	if (a->size == 0 || is_sorted(*a))
	{
		free(b.nums);
		return ;
	}
	else if (a->size < 6 && a->size > 0)
	{
		under6_handler(a, &b);
	}
	else if (a->size >= 6 && a->size > 0)
	{
		butterfly_sort(a, &b);
	}
	free(b.nums);
}

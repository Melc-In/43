/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:16:10 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/30 22:50:16 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*tab_copy(int *tab, size_t tab_size)
{
	size_t	i;
	int		*tab_cpy;

	tab_cpy = ft_calloc(tab_size, sizeof(int));
	i = 0;
	if (!tab_cpy || !tab)
		return (NULL);
	while (i < tab_size)
	{
		tab_cpy[tab_size - 1 - i] = tab[tab_size - 1 - i];
		i++;
	}
	return (tab_cpy);
}

static int	in_tab(int n, int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static int	is_next_min(int j, t_stack stack, int *exep, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < stack.size)
	{
		if (stack.nums[j] > stack.nums[i] && !in_tab(i, exep, filled))
			return (0);
		i++;
	}
	return (1);
}

static size_t	get_next_min(t_stack stack, size_t min, int	*exep, size_t fill)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack.size)
	{
		if (stack.nums[min] < stack.nums[j]
			&& is_next_min(j, stack, exep, fill))
			i = j;
		j++;
	}
	return (i);
}

void	normalize_stack(t_stack *a)
{
	t_stack	cpy;
	size_t	i;
	size_t	min;
	int		*exep;

	i = 1;
	cpy.nums = tab_copy(a->nums, a->size);
	cpy.size = a->size;
	exep = ft_calloc(a->size, sizeof(int));
	if (!cpy.nums || !exep)
	{
		free(exep);
		free(cpy.nums);
		return ;
	}
	min = get_min(*a);
	while (i < a->size + 1)
	{
		a->nums[min] = (int)i;
		exep[(int)i - 1] = min;
		min = get_next_min(cpy, min, exep, i);
		i++;
	}
	free(exep);
	free(cpy.nums);
}

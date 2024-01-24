/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:19:46 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/24 23:50:49 by cglandus         ###   ########.fr       */
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

static int	*tab_copy(int *tab, size_t tab_size)
{
	size_t	i;
	int	*tab_cpy;

	tab_cpy = ft_calloc(tab_size, sizeof(int));
	i = 0;
	if (!tab_cpy || !tab)
		return (NULL);
	while (i < tab_size)
	{
		tab_cpy[tab_size - 1 - i] = tab[tab_size - 1 - i];
		i++;
	}
	return(tab_cpy);
}

size_t	get_next_min(t_stack stack, size_t min)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack.size)
	{
		if (stack.nums[i] > stack.nums[j] && (j != min && stack.nums[min] < stack.nums[j]))
			i = j;
		j++;		
	}
	return (i);
}

static void	normalize_stack(t_stack *a)
{
	t_stack	cpy;
	size_t	i;
	size_t	min;

	i = 1;
	cpy.nums = tab_copy(a->nums, a->size);
	cpy.size = a->size;
	if (!cpy.nums)
	{
		free(cpy.nums);
		return ;
	}
	min = get_min(*a);
	while (i < a->size + 1)
	{
		a->nums[min] = (int)i;
		min = get_next_min(cpy, min);
		i++;
	}
}

void    butterfly_sort(t_stack *a, t_stack *b)
{
	int	chunck_size;
	int	i;

	i = a->size - 1;
	chunck_size = b->size;
	printf("a : \n\n");
	while (i >= 0)
	{
		printf("[%d] ", a->nums[i]);
		i--;
	}
	printf("\n");
	printf("\n");
	i = a->size - 1;
	normalize_stack(a);
	if (!a->nums)
		return ;
	printf("\n");
	printf("a (normalized) : \n\n");
	while (i >= 0)
	{
		printf("[%d] ", a->nums[i]);
		i--;
	}
	printf("\n");
}

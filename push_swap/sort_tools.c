/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:19:46 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/22 22:30:48 by cglandus         ###   ########.fr       */
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

int	*tab_copy(int *tab, size_t tab_size)
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

static int	*normalize_stack(t_stack *a)
{
	t_stack	cpy;
	size_t	i;
	int		j; //test

	i = 1;
	j = 0; //test
	cpy.size = a->size;
	cpy.nums = tab_copy(a->nums, a->size);
	if (!cpy.nums)
	{
		free(cpy.nums);
		return (NULL);
	}
	while (i < a->size + 1)
	{
		printf("Min : %zu\n", get_min(cpy));
		printf("---\n");
		j = cpy.size - 1;
		printf("COPY :\n");
		while (j >= 0)
		{
			printf("%d\n", cpy.nums[j]);
			j--;
		}
		printf("---\n");
		a->nums[get_min(cpy)] = (int)i;
		cpy.nums = trim_stack(&cpy, get_min(cpy));
		i++;
		cpy.size--;
	}
	free(a->nums);
	return (cpy.nums);
}

void    butterfly_sort(t_stack *a, t_stack *b)
{
	int	chunck_size;
	int	i;

	i = a->size - 1;
	chunck_size = b->size;
	while (i >= 0)
	{
		printf("%d\n", a->nums[i]);
		i--;
	}
	i = a->size - 1;
	a->nums = normalize_stack(a);
	if (!a->nums)
		return ;
	while (i >= 0)
	{
		printf("%d\n", a->nums[i]);
		i--;
	}
}

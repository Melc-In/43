/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:19:46 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/23 22:33:38 by cglandus         ###   ########.fr       */
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

static size_t	get_min_exep(t_stack stack, int	*exep, size_t n_elements)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < stack.size)
	{
		if (stack.nums[i] > stack.nums[j] && !in_tab(exep, j))
			i = j;
		if (n_elements == stack.size - 1)
		{
			printf("CACA");
			i = j;
		}
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

static void	normalize_stack(t_stack *a)
{
	t_stack	cpy;
	size_t	i;
	size_t	t_filled;
	int		*tab;
	int		j; //test

	i = 1;
	t_filled = 0;
	j = 0; //test
	tab = ft_calloc(a->size, sizeof(int));
	cpy.nums = tab_copy(a->nums, a->size);
	cpy.size = a->size;
	if (!cpy.nums || !tab)
	{
		free(cpy.nums);
		free(tab);
		return ;
	}
	while (i < a->size + 1)
	{
		a->nums[get_min_exep(cpy, tab, t_filled)] = (int)i;
		j = 0; //test
		printf("---\n"); //test
		printf("Min LIST :\n"); //test
		while (j < (int)a->size) //test
		{
			printf("%d\n", tab[j]); //test
			j++; //test
		}
		printf("---\n"); //test
		//cpy.nums = trim_stack(&cpy, get_min_exep(cpy, tab));
		printf("CURRENT Min : %zu\n", get_min_exep(cpy, tab, t_filled)); //test
		tab[i - 1] = get_min_exep(cpy, tab, t_filled);
		t_filled++;
		printf("---\n"); //test
		i++;
	}
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
	normalize_stack(a);
	if (!a->nums)
		return ;
	while (i >= 0)
	{
		printf("%d\n", a->nums[i]);
		i--;
	}
}

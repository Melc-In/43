/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/01 21:57:09 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_split(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	stack_builder(char **tab, t_stack *a, size_t i, size_t j)
{
	while (tab[i])
	{
		if (is_number(tab[j - 1]) && !in_stack(a, ft_atoi(tab[j - 1])))
		{
			a->filled++;
			a->nums[i] = ft_atoi(tab[j - 1]);
		}
		else
			return (0);
		j--;
		i++;
	}
	return (1);
}

static int	check_args(char *arg, t_stack *a)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	tab = ft_split(arg, ' ');
	a->nums = ft_calloc(size_stack(tab), sizeof(int));
	if (!a->nums)
	{
		free_split(tab, a->size);
		return (0);
	}
	a->size = size_stack(tab);
	a->filled = 0;
	j = size_stack(tab);
	if (!stack_builder(tab, a, i, j))
	{
		free_split(tab, a->size);
		return (0);
	}
	free_split(tab, a->size);
	return (1);
}

static int	no_quote(char **arg, t_stack *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size_stack(arg);
	a->nums = ft_calloc(size_stack(arg), sizeof(int));
	if (!a->nums)
		return (0);
	a->size = size_stack(arg) - 1;
	a->filled = 0;
	while (i < a->size || j - 1 > 0)
	{
		if (is_number(arg[j - 1]) && !in_stack(a, ft_atoi(arg[j - 1])))
		{
			a->filled++;
			a->nums[i] = ft_atoi(arg[j - 1]);
		}
		else
			return (0);
		j--;
		i++;
	}
	return (1);
}

int	parsing(int ac, char **args, t_stack *stack)
{
	if (args[1] && ac == 2)
	{
		if (check_args(args[1], stack))
			return (1);
	}
	if (ac > 2)
	{
		if (no_quote(args, stack))
			return (1);
	}
	return (0);
}

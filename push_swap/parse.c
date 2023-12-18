/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/18 16:35:58 by cglandus         ###   ########.fr       */
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

static int	check_args(char *arg, t_stack *a)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	tab = ft_split(arg, ' ');
	if (tab != NULL)
	{
		a->nums = ft_calloc(size_stack(tab), sizeof(int));
		a->size = size_stack(tab);
		j = size_stack(tab);
	}
	while (tab[i])
	{
		if (is_number(tab[j - 1]) && !in_stack(a, ft_atoi(tab[j - 1])))
			a->nums[i] = ft_atoi(tab[j - 1]);
		else
		{
			free_split(tab, a->size);
			return (0);
		}
		j--;
		i++;
	}
	free_split(tab, a->size);
	return (1);
}

int	parsing(int ac, char **args, t_stack *s)
{
	if (args[1] && ac == 2)
	{
		if (check_args(args[1], s))
			return (1);
		else
			return (0);
	}
	return (0);
}

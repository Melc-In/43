/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/11 18:44:13 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(char *arg, t_stack *a)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = ft_split(arg, ' ');
	if (tab != NULL)
	{
		a->nums = ft_calloc(size_stack(tab), 1);
		a->size = size_stack(tab);
	}
	while (tab[i])
	{
		if (is_number(tab[i]) && !in_stack(a, ft_atoi(tab[i])))
			a->nums[i] = ft_atoi(tab[i]);
		else
		{
			free(tab);
			return (0);
		}
		i++;
	}
	free(tab);
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

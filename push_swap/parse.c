/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/09 10:15:03 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (0);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	in_stack(t_stack *stack, int n)
{
	size_t	i;

	i = 0;
	while (stack->nums[i])
	{
		if (stack->nums[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static size_t	size_stack(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	check_args(char *arg, t_stack *a)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = ft_split(arg, ' ');
	a->nums = ft_calloc(size_stack(tab), 1);
	a->size = size_stack(tab);
	while (tab[i])
	{
		if (is_number(tab[i]) && !in_stack(a, ft_atoi(tab[i])))
			a->nums[i] = ft_atoi(tab[i]);
		else
			return (0);
		i++;
	}
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

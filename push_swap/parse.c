/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/06 22:34:24 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i][0] == '-')
		i++;
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (1);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	in_stack(t_stack stack, int n)
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

	i = 0
	while (tab[i])
		i++;
	return (i);
}

static int	check_args(char *arg)
{
	size_t	i;
	char	**tab;
	t_stack	*a;

	i = 0;
	tab = ft_split(arg, ' ');
	a->nums = malloc(size_stack(tab));
	while (tab[i])
	{
		if (is_number(str) || !in_stack(a, ft_atoi(tab[i])))
			a->nums[i] = ft_atoi(tab[i]);
		else
			return (1);
		i++;
	}
	return (0);
}

int	parsing(int ac, char **args)
{
	size_t	i;

	i = 1;
	if (ac > 2)
	{
		while (args[i])
		{
			if (!no_quote(args[i]))
				return (1);
			i++;
		}
		return (1);
	}
	if (args[i] & ac == 2)
	{
		if (!check_arg(args[i]))
			return (1);
		else
			return (0);
	}
	return (1);
}

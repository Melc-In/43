/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/01 22:13:12 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s;

	if (!s2 || ft_strlen(s2) == 0)
	{
		free(s1);
		return (NULL);
	}
	s = ft_strjoin(s1, s2);
	free(s1);
	return (s);
}

static int	stack_builder(char **tab, t_stack *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size_stack(tab);
	while (tab[i])
	{
		if (is_number(tab[j - 1]) && !in_stack(*a, i, ft_atoi(tab[j - 1])))
			a->nums[i] = ft_atoi(tab[j - 1]);
		else
			return (0);
		j--;
		i++;
	}
	return (1);
}

static int	check_arg(char *arg, t_stack *a)
{
	char	**tab;

	tab = ft_split(arg, ' ');
	a->nums = ft_calloc(size_stack(tab), sizeof(int));
	if (!a->nums || size_stack(tab) == 0 || !tab)
	{
		free_split(tab, a->size);
		return (0);
	}
	a->size = size_stack(tab);
	if (!stack_builder(tab, a))
	{
		free_split(tab, a->size);
		return (0);
	}
	free_split(tab, a->size);
	return (1);
}

int	multiple_args(char **args, char *all_args, int i, t_stack *stack)
{
	if (!all_args)
	{
		free(all_args);
		return (0);
	}
	all_args = ft_strjoin_free(all_args, " ");
	while (args[i])
	{
		all_args = ft_strjoin_free(all_args, args[i]);
		if (all_args == NULL)
			return (0);
		all_args = ft_strjoin_free(all_args, " ");
		i++;
	}
	if (check_arg(all_args, stack))
	{
		free(all_args);
		return (1);
	}
	free(all_args);
	return (0);
}

int	parsing(int ac, char **args, t_stack *stack)
{
	char	*all_args;
	int		i;

	i = 2;
	if (args[1] && ac == 2)
	{
		if (check_arg(args[1], stack))
			return (1);
	}
	if (ac > 2)
	{
		all_args = ft_strdup(args[1]);
		if (multiple_args(args, all_args, i, stack))
			return (1);
	}
	return (0);
}

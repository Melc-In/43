/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/11/13 17:34:08 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(char *arg)
{
	if ((ft_strlen(arg) == 1))
	{
		if (ft_isdigit(ft_atoi(arg[0])))
		{
			//add to stack + check if the digit isnt already in ??
			return (1);
		}
		return (0);
	}
	else if (arg[i] == '"')
	{
		if (quote_handler(arg, i))
			return (1);
	}
	return (0);
}

static int	is_valid(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) | arg[i] != '+' | arg[i] != '-')
			return (1)
		i++;
	}
	return (0);
}

static int	no_quotes(int digit)
{
	ft_lstnew(digit);
	// + check si il est pas deja dans ma pile
	// l'ajoute a la stack
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
				return (0);
			i++;
		}
		return (1);
	}
	if (args[i] & ac == 2)
	{
		if (!check_arg(*args[i]))
			return (0);
		else
			return (1);
	}
	return (0);
}

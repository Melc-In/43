/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:22 by cglandus          #+#    #+#             */
/*   Updated: 2023/08/04 07:23:22 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	check_stack(s_list stack)
//{
//}

static int	quote_handler(char *arg, size_t i)
{
	char	*splited_arg;
	size_t	i;

	i = -1;
	splited_arg = ft_strtrim(arg, "\"");
	splited_arg = ft_split(arg, arg[i + 1]);
	if (!splited_arg)
		return (0);
	while (arg[i++])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	ft_putstr_fd(splited_arg, 1);
	return (1);
}

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

static int	no_quotes(char *arg)
{
	if (ft_strlen(arg != 1)
			return (1);
	ft_atoi(arg[0])))
	//check si c un nombre signé ou pas
	// + check si il est pas deja dans ma pile
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
	if (args[i])
	{
		if (!check_arg(*args[i]))
			return (0);
		else
			return (1);
	}
	return (0);
}

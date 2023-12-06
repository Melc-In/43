/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:38:20 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/06 20:24:09 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int		*nums;
	size_t	size;
}			t_stack;

int	parsing(int ac, char **args);

#endif

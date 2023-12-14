/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:38:20 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/14 20:09:14 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*nums;
	size_t	size;
}			t_stack;

int		parsing(int ac, char **args, t_stack *s);

int		is_number(char *str);
int		in_stack(t_stack *stack, int n);
size_t	size_stack(char **tab);

void	swap(t_stack *s, char *mess);
void	push(t_stack *s1, t_stack *s2, char *mess);
void	rotate(t_stack *s, char *mess);
int    	pop(t_stack *a);

void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrab(t_stack *s, char *mess);
void	rrr(t_stack *a, t_stack *b);

#endif

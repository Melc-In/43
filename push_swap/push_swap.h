/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:38:20 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/04 00:50:50 by cglandus         ###   ########.fr       */
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

int		parsing(int ac, char **args, t_stack *stack);
void	switch_algo(t_stack *a);

void	free_split(char **tab, size_t size);
int		is_number(char *str);
int		in_stack(t_stack stack, size_t filled, long n);
int		is_sorted(t_stack stack);
int		contains_number(char *str);

size_t	get_max(t_stack stack);
size_t	get_min(t_stack stack);
size_t	size_stack(char **tab);

void	swap(t_stack *stack, char *mess);
void	push(t_stack *s1, t_stack *s2, char *mess);
void	rotate(t_stack *stack, char *mess);

void	ss(t_stack *a, t_stack *b, char *mess);
void	rr(t_stack *a, t_stack *b, char *mess);
void	rrab(t_stack *stack, char *mess);
void	rrr(t_stack *a, t_stack *b, char *mess);

void	butterfly_sort(t_stack *a, t_stack *b);

void	normalize_stack(t_stack *a);

#endif

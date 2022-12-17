/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:57:45 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/16 22:25:43 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

int	absol(int n);
int	print_hex(unsigned int n, char c);
int	print_ints(int n);
int	print_ptr(unsigned long long ptr);
int	print_uints(unsigned int n);
int	ft_printf(const char *str, ...);

#endif

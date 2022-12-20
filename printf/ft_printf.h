/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:57:45 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/20 18:50:22 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	absol(int n);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	print_hex(unsigned int n, char c);
int	print_ints(int n);
int	print_ptr(unsigned long long ptr);
int	print_uints(unsigned int n);
int	ft_printf(const char *str, ...);

#endif

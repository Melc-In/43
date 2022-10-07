/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 02:30:49 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// same as size_t

typedef unsigned long	t_size;

// memory manipulation fct

void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *dest, const void *src, t_size n);
void	*ft_memmove(void *dest, const void *src, t_size n);
void	*ft_memset(void *s, int c, t_size n);
void	*ft_calloc(t_size nmemb, t_size size);
char	*ft_strdup(const char *s);

// info fct

t_size	ft_strlen(char *str);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
int		ft_strncmp(const char *s1, const char *s2, t_size n);

// -is fct

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// utility fct

int		ft_atoi(const char *str);
t_size	strlcat(char *dest, const char *src, t_size n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, t_size n);

#endif

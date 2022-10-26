/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/17 19:47:43 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// same as size_t and NULL

# define T_NULL ((void *)0)

typedef unsigned long	t_size;

// memory manipulation fct

void	ft_bzero(void *s, t_size n);
void	*ft_memchr(const void *s, int c, t_size n);
void	*ft_memcpy(void *dest, const void *src, t_size n);
void	*ft_memmove(void *dest, const void *src, t_size n);
void	*ft_memset(void *s, int c, t_size n);
void	*ft_calloc(t_size nmemb, t_size size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, t_size len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);

// info fct

t_size	ft_strlen(const char *str);
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
char	*ft_itoa(int n);
t_size	ft_strlcat(char *dest, const char *src, t_size n);
t_size	ft_strlcpy(char *dest, const char *src, t_size n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, t_size n);

// outputs

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif

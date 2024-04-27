/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 18:29:33 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_param
{
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	eat_mtx;
	pthread_mutex_t	full_mtx;
	int				forks;
	int				first_time;
	int				ttd;
	int				tte;
	int				tts;
	int				n_toeat;
	int				must_eat;
	int				dead;
	int				full;
}	t_param;

typedef struct s_philo
{
	t_param			*param;
	pthread_t		thread;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	int				who;
	int				last_meal;
}	t_philo;

void	start_simm(t_philo *philo, t_param *param);

void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atol(const char *str);
int		ft_str_isdigit(char *str);
int		ft_strcmp(const char *s1, const char *s2);

int		get_time(void);
int		get_val(int value, pthread_mutex_t *m);
void	p_print(t_philo *philo, char *mess);
void	destroy_simm(t_philo *philo, t_param *param);

#endif

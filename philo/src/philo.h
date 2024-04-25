/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/25 05:30:24 by cglandus         ###   ########.fr       */
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

typedef struct s_greec
{
	pthread_t		thread;
	pthread_mutex_t	status_mtx;
	int				is_dead;
	int				n_meals;
}	t_greec;

typedef struct s_philo
{
	t_greec			*man;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	print_mtx;
	int				first_time;
	int				forks;
	int				who;
	int				ttd;
	int				tte;
	int				tts;
	int				n_toeat;
	int				must_eat;
}	t_philo;

void	start_simm(t_philo *philo);

void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atol(const char *str);
int		ft_str_isdigit(char *str);

int		get_time(void);
int		one_dead(t_philo *philo);
int		all_eat(t_philo *philo);
void	destroy_simm(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/24 23:06:29 by cglandus         ###   ########.fr       */
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

typedef struct s_greec
{
	int	is_dead;
	int	n_meals;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	status_mtx;
	pthread_mutex_t print_mtx;
}	t_greec;

typedef struct s_philo
{
	pthread_t	*t;
	s_greec		man;
	int	forks;
	int	ttd;
	int	tte;
	int	tts;
	int	n_toeat;
	int	must_eat;
	int	start_time;
}	t_philo;

void	start_simm(t_philo *philo);

long	ft_atol(const char *str);
int		ft_str_isdigit(char *str);

int		get_time(t_philo *philo);
int		one_dead(t_philo *philo);
int		all_eat(t_philo *philo);
void	destroy_simm(t_philo *philo);

#endif

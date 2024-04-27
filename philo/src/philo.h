/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/27 08:03:41 by cglandus         ###   ########.fr       */
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
	pthread_mutex_t	*dead_mtx;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*lfork_mtx;
	pthread_mutex_t	*rfork_mtx;
	pthread_mutex_t	*eat_mtx;
	pthread_mutex_t	*full_mtx;
	int				*first_time;
	int				*dead;
	int				nb_philo;
	int				last_meal;
	int				*full;
	int				who;
	int				ttd;
	int				tte;
	int				tts;
	int				n_toeat;
	int				must_eat;
}	t_greec;

typedef struct s_philo
{
	t_greec			*man;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	eat_mtx;
	pthread_mutex_t	full_mtx;
	int				full;
	int				dead;
	int				first_time;
	int				forks;
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
int		ft_strcmp(const char *s1, const char *s2);

int		get_time(void);
int		get_val(int value, pthread_mutex_t *m);
void	p_print(t_greec *man, char *mess);
void	*unlock_forks(pthread_mutex_t *f1, pthread_mutex_t *f2);
void	destroy_simm(t_philo *philo);

#endif

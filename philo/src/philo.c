/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:38 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/24 22:55:19 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	param_init(t_philo *philo, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_str_isdigit(argv[i]) || ft_atol(argv[i]) == 2147483648
			|| ft_atol(argv[i]) < 0)
			return (0);
		i++;
	}
	if (i == 5 || i == 6)
	{
		philo->n_phi = ft_atol(argv[1]);
		philo->ttd = ft_atol(argv[2]);
		philo->tte = ft_atol(argv[3]);
		philo->tts = ft_atol(argv[4]);
		philo->n_toeat = 0;
		philo->must_eat = 0;
		if (i == 6)
		{
			philo->must_eat = 1;
			philo->n_toeat = ft_atol(argv[5]);
		}
		return (1);
	}
	return (0);
}

static int	philo_init(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv);
	philo->start_time = tv.usec * 1000;
	if (pthread_mutex_init(philo->man->forks_mtx, NULL) != 0)
		return (0);
	if (pthread_mutex_init(philo->man->status_mtx, NULL) != 0)
		return (0);
	if (pthread_mutex_init(philo->man->print_mtx, NULL) != 0)
		return (0);
	philo->t = ft_calloc(philo->forks, sizeof(pthread_t));
	if (!philo->t)
		return (0);
	philo->man = ft_calloc(philo->forks, sizeof(t_greec));
	if (!philo->man)
	{
		if (philo->t)
			free(philo->t);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc > 1)
	{
		if (!param_init(&philo, argv))
			return (-1);
		if (!philo_init(&philo))
			return (-1);
		start_simm(&philo);
		destroy_simm(&philo);
	}
	return (0);
}

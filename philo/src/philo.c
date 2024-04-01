/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:38 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/01 08:25:44 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, char **argv)
{
	philo->n_phi = ft_atol(argv[1]);
	philo->ttd = argv[2];
	philo->tts = argv[3];
	philo->n_eat = 0;
	if (argv[4] && )
		philo->n_eat = ftargv[4];
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo_init(&philo, argv);
	return (0);
}

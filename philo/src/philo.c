/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:38 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/01 09:17:25 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_philo *philo, char **argv)
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
		philo->n_eat = -1;
		if (i == 6)
			philo->n_eat = ft_atol(argv[5]);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc > 1)
	{
		if (!philo_init(&philo, argv))
			return (0);
		printf("NB PHILOSOPHES : %d\n", philo.n_phi);
		printf("TIME TO DIE : %d\n", philo.ttd);
		printf("TIME TO EAT : %d\n", philo.tte);
		printf("TIME TO SLEEP : %d\n", philo.tts);
		printf("NB EACH PHILO MUST EAT : %d\n", philo.n_eat);
	}
	return (0);
}

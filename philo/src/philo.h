/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:44:35 by cglandus          #+#    #+#             */
/*   Updated: 2024/04/01 09:00:59 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo
{
	int	n_phi;
	int	ttd;
	int	tte;
	int	tts;
	int	n_eat;
}	t_philo;

long	ft_atol(const char *str);
int		ft_str_isdigit(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:09:53 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/28 21:07:08 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

typedef struct s_msg
{
	char			*message;
	int				len_mess;
	unsigned int	byte;
	int				bit_len;
	int				bit;
	int				i;

}	t_msg;

#endif

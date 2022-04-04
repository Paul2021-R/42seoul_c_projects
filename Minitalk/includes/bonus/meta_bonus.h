/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:59:13 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:18:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_BONUS_H
# define META_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include "../../library/libft/libft.h"
# include "../../library/ft_printf/mandatory/ft_printf.h"

typedef struct s_protocol
{
	struct sigaction	sa_pre;
	struct sigaction	sa_char;
	struct sigaction	sa_bit;
	pid_t				received_pid;
	int					index;
	int					printed;
	char				p;
}				t_protocol;

#endif 
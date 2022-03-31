/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:59:13 by haryu             #+#    #+#             */
/*   Updated: 2022/03/31 23:39:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_protocol
{
	pid_t	received_pid;
	int		index;
	char	p;
}			t_protocol;


void	error_print(int errorsign);
void	print_intro(int ac);

#endif 
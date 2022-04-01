/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:59:13 by haryu             #+#    #+#             */
/*   Updated: 2022/04/01 19:32:09 by haryu            ###   ########.fr       */
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
	int		printed;
	char	p;
}			t_protocol;


void	cli_error_print(int errorsign);
void	cli_print_intro(int ac);
int		cli_connect_ready(char *str, int code, pid_t serverpid);
void	cli_sighandler_pre(int signo, siginfo_t *info, void *data);
void	cli_sighandler_print(int signo, siginfo_t *info, void *data);
void	cli_sighandler_char(int signo);
void	cli_send_char_to_binary(char c);
void	cli_send_message(char *str);
void	initialize_signal(t_protocol *data, int code);

#endif 
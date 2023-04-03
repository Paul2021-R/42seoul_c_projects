/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:16 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:19:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "meta_bonus.h"

/* 클라이언트 초기 출력물 */
void	cli_print_intro(int ac);
/* 시그널 함수 초기화용 */
void	cli_sigaction_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *));
/* 클라이언트 연결 상태 처리용 */
void	cli_connect_ready(char *str);
/* 문자열 보내기 처리용 */
void	cli_send_message(char *str);
/* 문자 보내기 처리용 */
void	cli_send_char(char c);
/* 문자열 신호처리용 */
void	cli_sighandler_char(int signo, siginfo_t *info, void *data);
/* 연결 상태 처리용 */
void	cli_sighandler_pre(int signo, siginfo_t *info, void *data);
/* 문자 전체 보내기 전 수신용 + 수신 후 처리용 */
void	cli_sighandler_char(int signo, siginfo_t *info, void *data);
/* 1글자 처리 용 */
void	cli_sighandler_bit(int signo, siginfo_t *info, void *data);
#endif
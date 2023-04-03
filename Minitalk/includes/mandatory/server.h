/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:14 by haryu             #+#    #+#             */
/*   Updated: 2022/04/04 23:15:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "meta.h"

/* 서버 초기 출력물 */
void	ser_initialize_server(void);
/* 전역 변수 초기화 */
void	ser_initialize_signal(t_protocol *data);
/* 전역 변수 내 시그널 핸들러 초기화 */
void	ser_sigaction_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *));
/* 연결 상태 처리용 */
void	ser_sighandler_pre(int signo, siginfo_t *info, void *data);
/* 문자 전체 보내기 전 수신용 + 수신 후 처리용 */
void	ser_sighandler_char(int signo, siginfo_t *info, void *data);
/* 1글자 처리 용 */
void	ser_sighandler_bit(int signo, siginfo_t *info, void *data);
/* bit 수용 함수 */
void	ser_receiving_bit(void);
/* str 받기 전 연결 확인용 함수 */
void	ser_connection_ready(void);
/* 문장 받기 및 수신 완료 확인용 함수 */
void	ser_receiving_char(void);

#endif
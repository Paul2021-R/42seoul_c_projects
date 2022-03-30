/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:24:48 by haryu             #+#    #+#             */
/*   Updated: 2022/03/30 20:30:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act_old;

void	sigint_handler( int signo)
{
	int	ndx;

	printf("Ctrl-C 키를 눌루셨죠.\n");
	printf("3초간 대기하겠습니다. 이때 Ctrl-Z키를 눌러 주세요.\n");
	for (ndx = 3; 0 < ndx; ndx--)
	{
		printf( "%d 초 남았습니다.\n", ndx);
		sleep( 1);
	}
}

int	main( void)
{
	struct sigaction act;

	act.sa_handler = sigint_handler;  // 시그널 핸들러 지정
	sigfillset(&act.sa_mask);        // 모든 시그널을 블록
	sigaction(SIGINT, &act, &act_old);
	while (1)
	{
		printf("badyak.com\n");
		sleep(1);
	}
}
/*
]$ ./a.out
badyak.com
badyak.com
^CCtrl-C 키를 눌루셨죠.
3초간 대기하겠습니다. 이때 Ctrl-Z키를 눌러 주세요.
3 초 남았습니다.
2 초 남았습니다.
1 초 남았습니다.
^CCtrl-C 키를 눌루셨죠.
3초간 대기하겠습니다. 이때 Ctrl-Z키를 눌러 주세요.
3 초 남았습니다.
2 초 남았습니다.
1 초 남았습니다.
^Z
[1]+  정지됨               ./a.out
]$
*/
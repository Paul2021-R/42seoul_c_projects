/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sigaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:21:56 by haryu             #+#    #+#             */
/*   Updated: 2022/03/30 20:24:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void	sigint_handler( int signo)
{
	printf("Ctrl-C 키를 눌루셨죠!!\n");
	printf("또 누르시면 종료됩니다.\n");
	sigaction(SIGINT, &act_old, NULL);
}

int	main( void)
{
	act_new.sa_handler = sigint_handler;
	sigemptyset (&act_new.sa_mask);
	sigaction (SIGINT, &act_new, &act_old);
	while (1)
	{
		printf("badayak.com\n");
		sleep(1);
	}
}
/*

]$ ./a.out
badayak.com
badayak.com
badayak.com
^CCtrl-C 키를 눌루셨죠!!
또 누르시면 종료됩니다.
badayak.com
badayak.com
^C
]$

*/
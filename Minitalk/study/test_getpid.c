/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getpid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:23:59 by haryu             #+#    #+#             */
/*   Updated: 2022/03/30 21:55:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
   int   counter  = 0;
   pid_t pid;

   printf( "저의 프로세스 ID는 %d 입니다.\n", getpid());
   pid   = fork();

   switch(pid)
   {
   case -1  :
      printf( "자식 프로세스 생성 실패\n");
      return -1;
   case 0   :
      printf( "저는 자식 프로세스입니다. 내 프로세스 ID는 %d이며\n \
부모 프로세스 ID는 %d 입니다.\n", getpid(), getppid());
      break;
   default  :
      printf( "저는 부모 프로세스이며 ID는 %d 입니다.\n", getpid());
   }
	while(1)
	{
		printf("hello!\n");
		sleep(1);
	}
	return (0);
}
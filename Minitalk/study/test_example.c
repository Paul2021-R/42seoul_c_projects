/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:29:15 by haryu             #+#    #+#             */
/*   Updated: 2022/03/30 21:32:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main( void)
{
	pid_t	mypid;

	mypid = getpid();
	while (1)
	{
		printf("the process is %d\n", mypid);
		printf("hello world!\n");
		sleep(2);
	}
	return 0;
}
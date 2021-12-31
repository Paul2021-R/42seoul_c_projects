/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:32:27 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:55:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = 100;
	long int b = -2147483649;
	unsigned int c = 2147483659;
	char *d = "test. hello world";


	//printf("%d\n", INT_MIN);
	int ret = ft_printf("%d %d %u %s",a , b, c, d);
	printf ("%d", ret);
	return (0);
}
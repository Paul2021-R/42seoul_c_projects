/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:32:27 by haryu             #+#    #+#             */
/*   Updated: 2022/01/19 00:36:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int a = 100;
	long int b = -2147483648;
	unsigned int c = 21474;
	char *d = "test. hello world";
	int	e = 20;
	int	*ptr = &e;

	//int ret = ft_printf("self_printf : %c %d %d %u %s %x %X %p 33%%", 'k' ,a , b, c, d, e, e, ptr);
	//ft_printf("character : %c \n",'k');
	//ft_printf("string : %s \n", d);
	//ft_printf("integer d : %d \n", a);
	//ft_printf("integer (nag)d : %d         ", b);
	ft_printf("     test    \nhi\nteooood\n");
	//ft_printf("integer u : %u \n", c);
	//ft_printf("16base integer x : %x \n", e);
	//ft_printf("16base integer X : %X \n", e);
	//ft_printf("pointer P : %p \n", ptr);
	//int ret = ft_printf("percentage : 33 %% \n");
	//ft_printf("[\n]");
	//ft_printf("",);

	//ft_printf ("return : %d", ret);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:32:27 by haryu             #+#    #+#             */
/*   Updated: 2022/01/20 16:33:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret = ft_printf("test_c_no.5 :[ %c %c %c ]\n",'0', '0','1');
	int ret0 = printf("refe_c_no.5 :[ %c %c %c ]\n", '0', '0','1');
	printf("\n ret1 = %d, ret2 = %d\n\n", ret, ret0);


	int a = ft_printf("test_c_no.8 :[ %c %c %c ]\n",'2', '1', '0');
	int b = printf("refe_c_no.8 :[ %c %c %c ]\n", '2', '1', '0');
	printf("\n ret1 = %d, ret2 = %d\n\n", a, b);


	int ret1 = ft_printf("test_c_no.9 :[ %c %c %c ]\n", 0, '1', '2');
	int ret2 = printf("refe_c_no.9 :[ %c %c %c ]\n", 0, '1', '2');
	printf("\n ret1 = %d ret2 = %d\n\n", ret1, ret2);
	//error 처리 필요


	int c = ft_printf("test_s_no.9 : \n[%s] [%s] [%s] [%s] [%s]\n"," - ", "", "4", "", "2 ");
	int d = printf("refe_s_no.9 : \n[%s] [%s] [%s] [%s] [%s]\n"," - ", "", "4", "", "2 ");
	printf("\n ret1 = %d, ret2 = %d\n\n", c, d);
	
	//문장이 아무것도 없는 경우 출력 하는 경우 구분해야함
	//ft_printf("test_s_no.10 :[ NULL %s NULL ]\n", NULL);
	//printf("ref_s_no.10 :[ NULL %s NULL ]\n", NULL);

	// null 출력 처리 어떻게? 
	//ft_printf("test_p_no.6 : \n[ %p %p ]\n", LONG_MIN, LONG_MAX);
	//printf("ref_p_no.6 : \n[ %p %p ]\n", LONG_MIN, LONG_MAX);

	//ft_printf("test_p_no.8 : \n[ %p %p ]\n", ULONG_MAX, -ULONG_MAX);
	//printf("ref_p_no.8 : \n[ %p %p ]\n", ULONG_MAX, -ULONG_MAX);
	
	//ft_printf("test_p_no.9 :[ %p %p ]\n", 0 ,0);
	//printf("ref_p_no.9 :[ %p %p ]\n", 0 ,0);

	// error 관련 free 처리 필요해 보임.
	return 0;
}

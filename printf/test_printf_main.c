/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:32:44 by haryu             #+#    #+#             */
/*   Updated: 2021/12/31 23:12:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	/*
	printf("------------------------------------------------------\n");
	printf("* double quote : [\"]\n");
	printf("* backslah : [\\]\n");
	printf("* alert(BEL) : [\a]\n");
	printf("* backspace : [test \b]\n");
	//printf("* produce no further output : [test\c test]\n");
	printf("* escape : [test\etest]\n");
	printf("* formfeed : [test  \f  test]\n");
	printf("* new line : [test\nteest]\n");
	printf("* carriage return : [test\rtest]\n");
	printf("* horizontal tab : [test\ttest]\n");
	//printf("* NNN octal value? : [\NHN]\n");
	//printf("* HH hexadecimal value? : [\xHH]\n");
	//printf("* '\\UHHHHHHHH' : [\UHHHHHHHH]\n");
	//printf("* '\\uHHHH': [\uHHHH]\n");
	//printf("* \%b : [%b]\n");
	printf("* \%% : [%%]\n");
	//printf("* %q : [%q]\n");
	int a = 10;
	int a16 = 0x7ffc3f;
	char *b = "Hello World";
	char *c = "\n";
	char *d = "[%c]\n[%c]\n[%d]";
	int A_p;
	long l_a = 2147483648;
	printf("%d\n%s\n", a, b);
	printf("c[0] [%c]\nc[1] %c\n", c[0], c[1]);
	A_p=printf(d, b[0], b[4], a);
	//A_p=printf("pointer : %p\n", &a);
	//A_p=printf("pointer? : %x\n", a);
	//A_p=printf("pointer??: %X\n",a);
	printf("%i\n",A_p);
	printf("how use %%i : %i\n",a16);
	printf("%%d : %d\n", a16);
	printf("%%u : %u\n",0x7ffc3f);
	printf("%%x(X) : %x  %X\n", 16, 016);
	printf("%%ld : %ld\n", l_a);
	*/

	int	num1 = 1234;
	int *ptr_i = &num1;
	char char1 = 'a';
	char *ptr_c = &char1;

	printf ("포인터 체크_정수 : %ld\n",sizeof(ptr_i));
	printf ("포인터 체크_문자 : %ld\n", sizeof(ptr_c));
	printf ("포인터 위치_정수 : %p\n", ptr_i);
	printf ("포인터 위치_문자 : %p\n", ptr_c);
	printf ("포인터 위치_정수 : %x\n", *ptr_i);
	printf ("포인터 위치_문자 : %x\n", *ptr_c);
	printf ("포인터 위치_정수 : %p\n", &num1);
	printf ("포인터 위치_문자 : %p\n", &char1);

	unsigned int	u1 = 100;
	unsigned int	u2 = 023;
	unsigned int	u3 = 0xf1;
	unsigned int	u4;

	printf("unsigned int(10) : %u\n", u1);
	printf("unsigned int(8) : %u\n", u2);
	printf("unsigned int(16) : %u\n", u3);
	return 0;
}

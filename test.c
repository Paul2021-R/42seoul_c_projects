#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int a = 10;
	char b = 'b';
	static char *b_1;
	char b_2[10] = {"be happy"};
	char *b_3;

	b_3 = (char *)malloc(sizeof(char) * 10);

	printf("int type(stack) : %p\n", &a);
	printf("char type(stack) : %p\n", &b);
	printf("char type(static_data) : %p\n", &b_1);
	printf("char str type(stack) : %p\n", &b_2);
	printf("char str type(heap) : %p\n", &b_3);
	free(b_3);
	return 0;
}

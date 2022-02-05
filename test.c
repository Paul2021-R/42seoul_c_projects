#include <stdio.h>

int sum(int _a, int _b) {return _a + _b; }
int sub(int _a, int _b) {return _a - _b; }
int mul(int _a, int _b) {return _a * _b; }
void pri_result(int switcher, int a, int b, int(*pFunc)(int, int))
{
	char operand = 0;

	switch (switcher)
	{
		case 1 :
			operand = 43;
			break ;
		case 2 :
			operand = 45;
			break ;
		case 3 :
			operand = 42;
			break ;
		default :
			printf("you choose wrong operand signals\n");
	}
	printf("Your answer : %d %c %d = %d\n", a, operand, b, pFunc(a,b));
	return ;
}

int main(void)
{
	int a = 0, b = 0;
	int switcher = 0;

	printf("Please enter 2 numbers: ");
	scanf("%d %d", &a, &b);
	printf("Please choose which operand you use:\n1. sum 2.sub 3.mul:\n");
	scanf("%d", &switcher);
	int (*pFunc[3])(int, int) = { sum, sub, mul };
	pri_result(switcher, a, b, pFunc[switcher - 1]);
	return (0);
}

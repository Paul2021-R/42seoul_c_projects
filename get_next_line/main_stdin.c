#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *ret;

	ret = get_next_line(0);
	printf("%s", ret);

}

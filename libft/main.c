#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = "";
	int		value = 'a';

	printf("%p\n",memchr(s, value, 1900000000));
	printf("%p\n",ft_memchr(s, value, 1900000000));
}

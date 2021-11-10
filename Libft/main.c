/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:56:23 by haryu             #+#    #+#             */
/*   Updated: 2021/11/10 21:25:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

/*
extern int ft_isalpha(int c);

int	main(void)
{
	int a;
	char b;

	a = -2147483648;
	b = '!';
	printf("original : %d\n", isalpha(a));
	printf("original : %d\n", isalpha(b));
        printf("re-created : %d\n", ft_isalpha(a));
        printf("re-created : %d\n", ft_isalpha(b));
	return (0);
}

#include <stdio.h>
#include <ctype.h>

extern int ft_isdigit(int c);

int     main(void)
{
	char	*str;
	 int	i;

	i = 0;
	str = "B123456DMask";
	while (str[i])
	{
		printf("%c = %d\n",str[i] , isdigit(str[i]));
		i++;
	}
	i = 0;
	   while (str[i])
        {
                printf("%c = %d\n",str[i] , ft_isdigit(str[i]));
                i++;
        }
        return (0);
}

#include <stdio.h>
#include <ctype.h>

extern int ft_isalnum(int c);

int	main(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = 'Z';
	c = '~';

	printf("origin[%c] = %d\n", a, isalnum(a));
	printf("origin[%c] = %d\n", b, isalnum(b));
	printf("origin[%c] = %d\n", c, isalnum(c));
	printf("re_code[%c] = %d\n", a, ft_isalnum(a));
	printf("re_code[%c] = %d\n", b, ft_isalnum(b));
	printf("re_code[%c] = %d\n", c, ft_isalnum(c));
	return (0);
}


#include <stdio.h>
#include <ctype.h>

extern int ft_isascii(int c);

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;


	a = '0';
	b = 'Z';
	c = '~';
	d = 1000;

	printf("origin[%d] = %d\n", a, isascii(a));
	printf("origin[%d] = %d\n", b, isascii(b));
	printf("origin[%d] = %d\n", c, isascii(c));
	printf("origin[%d] = %d\n", d, isascii(d));
	printf("origin[%d] = %d\n", a, ft_isascii(a));
	printf("origin[%d] = %d\n", b, ft_isascii(b));
	printf("origin[%d] = %d\n", c, ft_isascii(c));
	printf("origin[%d] = %d\n", d, ft_isascii(d));
	return (0);
}


#include <stdio.h>
#include <ctype.h>

extern int ft_isprint(int c);

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;


	a = '0';
	b = 1;
	c = '~';
	d = 127;

	printf("origin[%d] = %d\n", a, isprint(a));
	printf("origin[%d] = %d\n", b, isprint(b));
	printf("origin[%d] = %d\n", c, isprint(c));
	printf("origin[%d] = %d\n", d, isprint(d));
	printf("re_code[%d] = %d\n", a, ft_isprint(a));
	printf("re_code[%d] = %d\n", b, ft_isprint(b));
	printf("re_code[%d] = %d\n", c, ft_isprint(c));
	printf("re_code[%d] = %d\n", d, ft_isprint(d));
	return (0);
}

#include <stdio.h>
#include <string.h>
#include "libft.h"

extern size_t ft_strlen(const char *s);

int	main(void)
{
	char	*s;
	int	a;
	int	b;

	a = strlen(s);
	b = ft_strlen(s);

	s = "Hello World";
	printf("origin[%d]\n", a);
	printf("re_code[%d]\n", b);
	return (0);
}

extern void *ft_memset(void *d, int c, size_t len);

int	main(void)
{
	char	arr[] = "Blockdmask blog";
	char	arr_re[] = "Blockdmask blog";
	char	c;
	int	len;

	c = 'c';
	len = 5;
	memset(arr, c, len * sizeof(char));
	ft_memset(arr_re, c, len * sizeof(char));
	printf("original = %s\n",arr);
	printf("re_code = %s\n",arr_re);
	return (0);
}

extern void ft_bzero(void *s, size_t n);

int main(void)
{
	char	arr[] = "Hello World";
	char	arr2[] = "Hello World";
	
	bzero(arr, 5 * sizeof(char));
	for (int i = 0; i < (sizeof(arr)/sizeof(char)); i++)
		printf("%c", arr[i]);
	printf("\n");
	ft_bzero(arr2, 5);
	for (int i = 0; i < (sizeof(arr2)/sizeof(char)); i++)
		printf("%c",arr2[i]);
	printf("\n");
	return (0);
}
*/

extern void *ft_memcpy(void *restruct dest, const void *restrict src, size_t n);

int main(void)
{

}

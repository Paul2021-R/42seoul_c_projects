#include <stdlib.h>
#include <stdio.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len-- > 0 && tmp_dst)
			*tmp_dst++ = *tmp_src++;
		*tmp_dst = '\0';
	}
	else
	{
		*(tmp_dst + len) = '\0';
		while (len-- && tmp_dst)
			*(tmp_dst + len) = *(tmp_src + len);
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strnjoin(char *s1, char *s2, size_t byte)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(ret, s1, byte);
	if (byte > len1)
		ft_memmove(ret + len1, s2, (byte - len1));
	return (ret);
}

int	main(int ac, char **av)
{
	(void)ac;
	printf("완성본(s1 + s2)\n[%s]\n", ft_strnjoin(av[1], av[2], atoi(av[3])));
	printf("완성본(s2)\n[%s]\n", ft_strnjoin("", av[2], atoi(av[3])));
	printf("완성본(s1)\n[%s]\n", ft_strnjoin(av[1], "", atoi(av[3])));
}

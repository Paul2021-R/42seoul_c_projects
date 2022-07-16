#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s);
	ret = malloc(sizeof(char) * len);
	i = -1;
	while(++i <= len)
		ret[i] = s[i];
	return (ret);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char	total[7000000];
	char	buff;
	int		cnt;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cnt = read(fd, &buff, 1);
	i = 0;
	while(cnt > 0)
	{
		total[i] = buff;
		if (total[i] == '\n')
			break ;
		cnt = read(fd, &buff, 1);
		i++;
	}
	total[++i] = '\0';
	if (cnt <= 0 || i == 0)
		return (NULL);
	return (ft_strdup(total));
}

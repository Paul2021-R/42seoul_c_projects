#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	i = -1;
	while(++i <= len)
		ret[i] = str[i];
	return (ret);
}

char	*get_next_line(int fd)
{
	char	total[7000000];
	char	buffer;
	int		cnt;
	int		i;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	i = 0;
	cnt = read(fd, &buffer, 1);
	while (cnt > 0)
	{
		total[i] = buffer;
		if (total[i] == '\n')
			break ;
		cnt = read(fd, &buffer, 1);
		i++;
	}
	total[++i] = 0;
	if (cnt <= 0 || i == 0)
		return (NULL);
	return (ft_strdup(total));
}

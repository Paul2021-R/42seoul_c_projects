#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	int	limit;
	char	*ret;

	limit = ft_strlen(str);
	ret = malloc(sizeof(char) * limit);
	if (!ret)
		return (NULL);
	i = -1;
	while(++i < limit)
		ret[i] = str[i];
	return (ret);
}

char *get_next_line(int fd)
{
	char	total[7000000];
	char	buffer;
	int		i;
	int		cnt;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	cnt = read(fd, &buffer, 1);
	while(cnt > 0)
	{
		total[i++] = buffer;
		if (buffer == '\n')
			break ;
		cnt = read(fd, &buffer, 1);
	}
	total[i] = 0;
	if (i == 0 || cnt < 0)
		return (NULL);
	return (ft_strdup(total));
}

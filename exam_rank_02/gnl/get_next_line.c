#include "get_next_line.h"

char	*ft_strndup(char *str, size_t byte);
char	*strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	free_for_err(char *str);
int		find_new_line(char *target);
char	*str_calloc(size_t size, int type);
int		make_total(int fd, char *total);
int		make_ret(char *total, char *ret);
int		make_new_total(char *total);

char *get_next_line(int fd)
{
	static char	*total;
	char		*ret;
	int			erno;
	
	if (fd < 0 || BUFFER_SIZE <=  0)
		return (NULL);
	erno = make_total(fd, total);
	if (erno < 0)
		return (NULL);
	erno = make_ret(total, ret);
	if (erno < 0)
		return (NULL);
	erno = make_new_total(total);
	if (erno < 0)
		return (NULL);
	return (ret);
}

char	*ft_strndup(char *str, size_t byte)
{
	char	*ret;
	int		i;

	if (!str || byte < 0)
		return (NULL);
	ret = str_calloc(byte + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < byte)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

char	*strjoin(char *s1, char *s2)
{}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		find_new_line(char *target)
{
	int	i;

	if (!target)
		return (-2);
	i = 0;
	while (target[i] != '\n' || target[i])
		i++;
	if (target[i] == '\n')
		return (i);
	else if (target[i] == '\0')
		return (-1);
}

char	*str_calloc(size_t size, int type)
{
	char	*ret;
	int		i;
	
	ret = malloc(size * type);
	if (!ret)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		*(ret + i) = 0;
		i++;
	}
	return (ret);
}

int		make_total(int fd, char *total)
{
	char	*buff;
	int		count_read;
	int		i;

	if (!total)
		total = ft_strndup("", 1);//여기서 하면 안될지도..?
	if (!total)
		return (-1);
	buff = str_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
	{
		free(total);
		return (-1);
	}
	count_read = read(fd, buff, BUFFER_SIZE);
	strjoin(total, buff);
	if (!total)
	{
		free(buff);
		return (-1);
	}
	while (find_new_line(total) == -1 && count_read > 0)
	{
		count_read = read(fd, buff, BUFFER_SIZE);
		if (count_read == 0)
			break ;
		buff[count_read] = '\0';
		strjoin(total, buff);
		if (!total)
		{
			free(buff);
			return (-1);
		}
	}
	free(buff);
	return (0);
}

int		make_ret(char *total, char *ret)
{
	int i;
	int	limit;

	i = 0;
	limit = find_new_line(total);
	if (limit < 0)
	{
		ret = ft_strndup(total, ft_strlen(total));
		if (!ret)
		{
			free(total);
			return (-1);
		}
		return (0);
	}
	ret = str_calloc(limit + 1, 1);
	if (!ret)
	{
		free(total);
		return (-1);
	}
	while ((i < limit) && total[i] != '\n')
	{
		ret[i] = total[i];
		i++;
	}
	ret[i] = '\n';
	return (0);
}

int		make_new_total(char *total)
{}

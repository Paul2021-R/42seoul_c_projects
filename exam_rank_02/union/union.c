#include <stdio.h>
#include <unistd.h>

static int ft_strlen(char *str);
static void ft_check_1(char *s1, char *s2);
static void ft_check_2(char c, char *str, int index);

int main(int ac, char **av)
{
	int i;
	int j;
	int av_len1;
	int av_len2;

	if (ac < 3 || ac > 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	av_len1 = ft_strlen(av[1]);
	av_len2 = ft_strlen(av[2]);
	i = 0;
	while (av[1][i])
	{
		j = 0;
		while (av[1][j])
		{
			if (av[1][i] == av[1][j] && i > j)
				break;
			if (j + 1 == av_len1)
				write(1, &av[1][i], 1);
			j++;
		}
		i++;
	}
	ft_check_1(av[2], av[1]);
	write(1, "\n", 1);
	return (0);
}

static void	ft_check_1(char *s1, char *s2)
{
	int	i;
	int	j;
	int	limit;

	i = 0;
	limit = ft_strlen(s2);
	//printf("limit : %d\n", limit);
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			//printf("%c\n", s1[i]);
			if (s1[i] == s2[j])
				break ;
			if (j + 1 == limit)
			{
				//printf("\n[%c]\n",s1[i]);
				ft_check_2(s1[i], s1, i);
			}
			j++;
		}
		i++;
	}
	return ;
}

static void ft_check_2(char c, char *str, int index)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i] && index > i)
			return ;
		if (str[i + 1] == '\0')
			write(1, &c, 1);
		i++;
	}
	return ;
}

static int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// 반복문 횟수 
// 1 번 문자열에 대해 자기 자신과 검사가 들어가야 함 
// -> 자기자신이랑 같은 인덱스 -> 스킵
// -> 자기자신보다 빠른 인덱스 -> 출력 안하고 안쪽 반복문 탈출
// 2 번 문자열에 대해 1번 문자열에서 검사 들어가야 함
// 1 번 문자열 통과 후 2번 문자열에서 검사 들어가야 함 

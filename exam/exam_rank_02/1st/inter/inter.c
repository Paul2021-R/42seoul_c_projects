#include <unistd.h>

void	str_check_1(char c, char *s1, char *s2, int index, int code);
void	str_check_2(char c, char *s2, int index, int code);

int main(int ac, char **av)
{
	int i;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		str_check_1(av[1][i], av[1], av[2], i, 1);
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		str_check_1(av[2][i], av[1], av[2], i, 2);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

void str_check_1(char c, char *s1, char *s2, int index, int code)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (code == 1 && s1[i] == c && index > i)
			return ;
		if (s1[i] == c && code == 2)
			return ;
		i++;
	}
	str_check_2(c, s2, index, code);
	return ;
}

void str_check_2(char c, char *s2, int index, int code)
{
	int	i;
	
	i = 0;
	while (s2[i])
	{
		if (code == 1 && c == s2[i])
		{
			write (1, &c, 1);
			break ;
		}
		if (code == 2 &&c == s2[i] && index > i)
			return ;
		i++;
	}
	return ;
}
// 로직 
// 1) s1 요소 -> 한번도 출력이 안됨 -> s2 배열에서 존재함 -> 출력 
// 2) s2 요소 -> s1에 존재하나

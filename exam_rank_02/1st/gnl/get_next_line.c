#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int i;
	int	limit;
	char *ret;

	limit = ft_strlen(str);
	ret = malloc(sizeof(char) * limit);
	if (!ret)
		return (NULL);
	i = 0;
	while(i < limit)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*ret;
	int		cnt;
	int		i;
	char	buffer;
	char	total[7000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
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
	if (cnt <= 0)
		return (NULL);
	return (ft_strdup(total));
}
/*
 * fd 값으로 읽어낸 줄 중에 개행문자를 가지고 있는 경우의 라인을 출력한다. EOF 를 만나게 되어도 출력한다. 
 * 읽은 라인의 끝에 개행문자가 있는 경우 개행문자를 포함하여 반환한다. EOF 에 도달시, 현재 char * 안에 담긴 최근의 버퍼를 반드시 저장하고, 반환한다. 
 * 만약 버퍼가 비어있다면 널을 반환할 것. 
 * 에러의 경우 NULL을 반환한다. NULL을 반환하는 경우가 아니면, 포인터는 반드시 free 가능해야 한다. 
 * 
 * 메모리 누수가 있어선 안되며, EOF 도달시, 당신의 함수는 말록으로 할당되는 메모리가 0을 유지해야하고 반환될 라인만을 제외한 상태여야 합니다. 
 *
 * 그러므로 루프 내에서 당신의 함수를 호출하는 것은 당신이 읽는 것을 허락해줍니다. 읽는 것은 fd ㄷ에서 이용 가능한 텍스트를 즉시 한 줄에서 텍스트의 끝까지 읽는 것을 말합니다. 그것의 라인중 한줄 혹은 텍스트이든 관계 없이
 *
 * 당신의 함수가 파일로부터 read를 할때 잘 행동하는지 확인하고, 표준 출력에서되는지, 리다이렉션 등등에서 잘 동작하는지 확인하십시오. 
 *
 * get_next_line 의 두번의 호출 사이에 fdㅇ상에 또다른 호출은 없을 것입니다. 마지막으로 바이너라 파일에 대한 읽기에선 지정되지 않은 행동을 취하는 것으로 생각합니다. 
 * */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/07 17:52:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	get_next_newl(char *findstr)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(findstr))
		if (findstr[i] == 10)
			return (i);
	return (0);
}

static char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	size_t	limit;
	char	*ret;

	i = 0;
	limit = n;
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
	{	free(ret);
		return (NULL);
	}
	while (i < limit)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*free_with_join(char *backup, char *buffer, int check)
{
	char	*ret;

	ret = ft_strjoin(backup, buffer);
	if (check != 1)
		free(backup);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*back[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int		end_addr;
	int		read_cnt;
	char		*ret;

	
	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	read_cnt = 0;
	while (1)
	{
		read_cnt++;
		end_addr = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		back[fd] = free_with_join(back[fd], buff, read_cnt);
		printf("%s\n",back[fd]);
		end_addr = get_next_newl(back[fd]);
		if (end_addr != 0)
			break ;
	}
	ret = ft_strndup(back[fd], end_addr);
	end_addr = (end_addr - (read_cnt * BUFFER_SIZE)) * -1;
	back[fd] = ft_strjoin("", buff + (BUFFER_SIZE - end_addr + 1));
	printf("remain : %s\n", back[fd]);
	return (ret);
}
/*
 * 전체 열을 담을 줄
 * 기존처럼 ret은 일시적인 포인터 배열로 복사(strndup)
 * 마지막 인덱스를 활용하여 사용한 영역을 free및 최적화 할 수 있도록 하고, 남은 부분이 발생 시 복사해둘 backup공간 확보 
 * 두번째 진행해야하는 경우 back을 확인하고 
 * 
 * 현재 상황 
 * 1. 최초 문장에선 제대로 출력 됨 2회차 때도 문제가 없었음. 그러나 3번째 검색이 되었을 때부터 문제 생김. 
 * free를 시켜야 할 때와 아닐때 구분이 제대로 안되고 있음. 파악 필요함. 
 * */

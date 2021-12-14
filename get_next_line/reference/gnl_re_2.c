/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:45:55 by haryu             #+#    #+#             */
/*   Updated: 2021/12/05 23:47:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_newl(int fd, char *src, int last_point)
{
	unsigned int	i;
	int		get_byte;
	unsigned int	total_byte;

	get_byte = 0;
	total_byte = 0;
	if (last_point != 0)
		i = last_point;
	else
		i = 0;
	while (1) 
	{
		get_byte = read(fd, src + total_byte + last_point, BUFFER_SIZE);
		if (get_byte == 0)
			total_byte += BUFFER_SIZE;
		else if (get_byte > 0)
			total_byte += get_byte;
		while (src[i])
		{
			if (src[i] == 10)
				return (i);
			i++;
		}
		if (get_byte == 0)
			break ;
	}
	return ((int)ft_strlen(src));
}

char	*get_next_line(int fd)
{
	static char	*total_read; //계속 저장할 문장 영역 
	char		*ret; //반환할 문장
	int			index_s; // 문장 시작 인덱스
	static int		index_e; // 개행문자 발견 인덱스

	if (!total_read)
	{
		total_read = (char *)malloc(sizeof(char) * 1000000);
		if (!total_read)
		{
			free(total_read);
			return (NULL);
		}
	}
	index_s = 0;
	if (index_e != 0)
		index_s = index_e + 1;
	index_e = get_next_newl(fd, total_read, index_s);
	ret = ft_strndup(total_read + index_s, index_e - index_s);
	if (!ret)
		return (NULL);
	return (ret);
}
/* 요구 행동 방식 : 
 * get_next_line  호출시-> 항상 한 줄씩을 읽어 내야 함. 
 * 한 줄 읽고 난 뒤 다시 호출 당하면? -> 그 다음 라인을 호출 해야 함
 * 더 이상 읽어 들일 내용이 없으면? -> NULL 반환
 * read 함수는 반드시 BUFFER_SIZE로 지정된 수준에서 이어져야 함
 * BUFFER_SIZE는 유동적임을 고려해서 지속적으로 읽어 들일 수 있도록 되어 있어야 함. 
 * 가능한 적게 읽어야 함. 즉, 제공되는 버퍼사이즈를 활용해서 읽어야 하는 만큼만 읽는 게 핵심이다. 
 *	즉, 1회로 읽을 만큼을 주는 경우보다, 수회 읽어내야 하는 구조를 만들어 내야 함. 
 * gnl을 호출할 때, 최초 호출한 경우와 다른 fd를 불러온다면? 이에 대해선 undefined behavior이므로 어떻게 해도 상관은 없다. 
 * 바이너리 파일을 읽는 것에 대해선 undefined behavior를 일으킨다. 단, 논리적 구현도 가능하다고 한다. 
 * 
 * 로직 재 설계 : 
 * 1. 최초 read 진행함
 * 1-1. 기존의 값이 존재하는 지 확인함. -> 
 * 	[1] 기존값 없을시 -> \n을 찾아야함 
 * 		[1.1] 최초 read된 값에서 \n찾기 
 * 			[1.1.1] \n이 없음 -> 추가로 read가 되어야함(반복문)
 * 			[1.1.2] \n 발견됨 -> 개행 부분에 대하여 발견하고, 인덱싱함
 * 				[1.1.2.1] 인덱싱을 활용하여 반환할 문장을 지금까지 read 한 문장에서 복사하여 반환한다. 
 * 	[2] 기존 값이 있을 시, 비교하여 다음 개행 전까지 가는 구조를 만들어야 함. 
 * 		[2.1] 기존 값에 \n 이 걸리지 않을 기믹을 만들어야함+ 추가 버퍼사이즈만큼 읽어드리기 
 * 			[2.1.1] [1.1.1] 인 경우로 이어짐(반복)
 * 			[2.1.2] [1.1.2] 진행 
 * 				[2.1.2.1] 인덱싱을 발견, 기존의 인덱싱 + 1 부터 새로운 인덱싱까지 복사하여 반환한다. 
 * */


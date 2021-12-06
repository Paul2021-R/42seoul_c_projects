/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/06 14:52:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		malloc_str(char *str, int times)
{}

int		get_next_newl(int fd, char *src)
{}

char	*get_next_line(int fd)
{
	char			*ret;
	static	char	*total;
	static	char	*remainder;
	static int		left_point;
	static int		e;

	if (!fd)
		return (NULL);
	e = get_next_newl(fd, total, s);



	return (ret);
}
//static 변수 셋팅 바꾸기 -> 버퍼사이즈에 맞춰서 진행하는 방식..?
//마지막 인덱싱 값을 활용하여 read 
//read하여 리턴 값으로 저장하기
//남은 데이터를 옮기기
//기존static변수를 free 하기
//
//42 + 42 + 42 = 126
//e = 72
//left = 126 - 72 = 55

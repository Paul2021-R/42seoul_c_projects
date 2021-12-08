/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:29:36 by haryu             #+#    #+#             */
/*   Updated: 2021/12/08 21:54:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	save_str(char *dst, char *src)

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff[BUFFER_SIZE + 1];
	int			read_cnt;
	char		*ret;

	if (fd < 0 || !fd || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == -1)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		backup = save_str(backup, buff);
	}
}

/*
1. call gnl
2. check error 
3. start read(1) -> check \n
3.1 \n O -> return from start point to \n point. 
	//using malloc 1) ret -> dont need free
3.1.1 backup remain part 
	//using malloc 1) backup -> need to free earlier backup
3.2 \n X -> backup buffer array and re read. 
3.2.1 buffer data move to backup 
	//using mlalloc 1) backup -> need to free earlier backup
3.2.1 find more to find \n in lines
	goto 3.1 or 3.2 

for this... 
need function 
	(1) backup func (backup, buffer)
	(2) ret func (backup)
		it can be unified with cut array func to optimize backup array.
*/

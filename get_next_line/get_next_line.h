/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:46:25 by haryu             #+#    #+#             */
/*   Updated: 2021/12/09 15:14:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifdef _WIN32
#  include <io.h> //window 호환을 위한 헤더파일. 
# else
#  include <unistd.h> //unix 시스템을 위한 헤더
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_str
{
	char	*total;
	int	read_cnt;
}			t_str;

char	*get_next_line(int fd);
char	get_next_line_utils(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, void *src, size_t len);
void	str_free(char *str);
char	*ft_calloc(size_t size);

#endif	

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:46:25 by haryu             #+#    #+#             */
/*   Updated: 2021/12/14 20:31:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <limits.h>

# ifdef _WIN32

#  include <io.h>

# else

#  include <unistd.h>

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef ARRAY_MAX
#  define ARRAY_MAX 12800
# endif

typedef struct s_str
{
	char		*backup;
	int		i_fd;
	struct s_str	*next;
}	t_str;

char	*get_next_line(int fd);
char	get_next_line_utils(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	free_all(t_str **head, t_str **node, int fd);
#endif	

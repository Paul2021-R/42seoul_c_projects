/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu </var/mail/root>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:43:05 by haryu             #+#    #+#             */
/*   Updated: 2021/12/27 16:33:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifdef _WIN32

#  include <io.h>

# else

#  include <unistd.h>

# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char		*backup;
	int		i_fd;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
char	get_next_line_utils(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	free_all(t_list **head, t_list **node, int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:10:22 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 20:25:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/ft_printf/mandatory/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_pushlist
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*array;
	int		max_len;
}			t_pushlist;

void	put_error(void);
int		*error_check(int limit, char **array);
void	fill_stack(t_pushlist **push, int ac);
void	lst_print(t_pushlist **push);

#endif 
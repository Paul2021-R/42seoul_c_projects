/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:10:22 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 00:51:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/ft_printf/mandatory/ft_printf.h"

# include <stdio.h>

typedef struct s_pushlist
{
	t_list	*integer;
	t_list	*sortorder;
	int		max_len;
}			t_pushlist;

void	put_error(void);
int		*error_check(int limit, char **array);
/*
 * error 점검 및 int 배열 반환
*/
void	fill_stack(int *array, t_pushlist *stack_a, int ac);
void	fill_stack_empty(int code, t_pushlist *stack_b, int ac);
/*
 * stack 자료구조에 저장하는 형태, stack b 초기화
*/
void	lst_print(t_pushlist **stack, t_pushlist **stack_b);
/*
 * stack 내부 저장 상태 확인용
*/

/*
	rules
	- no global variables 
	- sort with ascending 
	- when error occurs, show Error\n
	- print instructions with new line.
	- parameters rules
		modify ft_atoi -> 
		it needs to check error if number overcomes INTMAX 
		and INTmin => that time I need to check error !(clear)
		no integer -> Error(clear)
		no duplicates -> Error (clear)
		bigger than integer MAX, min -> Error (clear)
*/

#endif 
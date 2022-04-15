/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:10:22 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 00:18:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/ft_printf/mandatory/ft_printf.h"

/* 함수용 매크로 */
# define ALL 1
# define SPE 0;

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
	int		lis_len;
	int		len_b;
}			t_pushlist;

/* Forbidden utils */
/* 현재 스텍 확인용 */
void	lst_print(t_pushlist **push);
/* LIS array 확인용 */
void	lis_print(t_pushlist **push);

/* Initialize funcs */
/* Error 출력 */
void	put_error(void);
/* 예외 조건 점검 */
int		*error_check(int limit, char **array);
/* 최초 스택 정렬용 */
void	fill_stack(t_pushlist **push, int ac);
/*lis array 작성*/
void	get_lis(t_pushlist **push);

/* LIS array utils */
/* LIS 초기화 */
int		*array_malloc_to_zero(int length);
/* LIS 이분탐색을 활용한 알고리즘 n log n */
int		lower_bound(int *array, int value, int s, int e);
/* LIS 구성 */
void	make_lis(int *array, int **ret, int ref_i, int max_len);
/* LIS 리스트 길이 확인 */
int		find_lis_len(int *array, int max_len);
/* LIS 최솟값 찾기 */
int		find_minimun(int *array, int max_len);

/* t_node 자료용 함수  */
t_node	*ft_push_lstnew(int value);
t_node	*ft_push_lstlast(t_node *lst);
void	ft_push_lstadd_back(t_node **lst, t_node *new);
void	ft_push_lstadd_front(t_node **lst, t_node *new);
void	ft_push_lstclear(t_node **lst);
void	ft_push_lstdelone(t_node *lst);
int		ft_push_lstsize(t_node *lst);
/* 마지막 직전 노드 확인용 */
t_node	*ft_push_lstlast_early(t_node *lst);

/* sortting actions */
void	pb(t_pushlist **push);
void	pa(t_pushlist **push);
void	sa(t_pushlist **push, int code);
void	sb(t_pushlist **push, int code);
void	ss(t_pushlist **push);
void	ra(t_pushlist **push, int code);
void	rb(t_pushlist **push, int code);
void	rr(t_pushlist **push);
void	rra(t_pushlist **push, int code);
void	rrb(t_pushlist **push, int code);
void	rrr(t_pushlist **push);

#endif 
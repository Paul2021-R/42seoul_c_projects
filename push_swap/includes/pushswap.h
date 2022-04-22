/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:10:22 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 02:09:43 by haryu            ###   ########.fr       */
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

/* Initialize funcs */
/* Error 출력 */
void	put_error(void);
/* 예외 조건 점검 */
int		*error_check(int limit, char **array);
/* 예외 조건 점검 - LIS를 위해 정리중 이미 정렬이 마무리 되었을 때. */
void	check_already_done(t_pushlist **push);
/* 예외 조건 점검 - 예외 상태 파악용 */
int		check_score_already_done(t_node *tmpa, int max_len);
/* 예외 조건 */
void	exception_lis(t_pushlist **push);
/* 스택 <= 2 */
void	exception_lis_stack_2(t_pushlist **push);
/* 스택 = 5, lis <= 2  */
void	exception_lis_2(t_pushlist **push);

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
/* LIS 최솟값과 해당 인덱스 찾기 */
int		find_minimun(int *array, int max_len, int *index);
/* LIS 정렬 */
void	align_stack_a(t_pushlist **push, int min_value, int min_pos);
/* LIS 배열 스택 재정렬시 재 초기화 용 */
void	array_copy_from_stack(t_pushlist **push);

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
/* node 최솟값 */
int		ft_push_min(t_node *stack);
int		where_is_node(t_node *stack, int target);

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

/* sorting algorithm */
/* 스택 B 최선의 선택 스위쳐 */
void	check_best_choice(t_pushlist **push);
/* LIS 정렬 알고리즘 코어  */
void	lis_algorithm(t_pushlist **push, int value);
/* score 확인하기 */
int		check_score_a(t_node *stack, int value);
int		check_score_b(t_node *stack, int value, int len_b);
/* score가 음양 한 쪽으로 몰릴 때 */
int		get_score_for_both_same(int score_a, int score_b);
/* 스코어 a의 기준 리턴값 확인 */
int		check_standard_for_a(t_node *stack, int value, int length, int limit);
#endif 

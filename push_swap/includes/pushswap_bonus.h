/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:32:30 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 16:56:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "pushswap.h"
# include "forbiden.h"

/* argument = 1, make seperated */
int		check_height(char **target);
char	**make_target(int ac, char **av, t_pushlist **push);

/* error */
/* terminate program */
void	put_error(void);
/* 인자 문제 여부 확인 */
int		*error_check(int limit, char **array);
/* stack A 저장 */
void	fill_stack(t_pushlist **push, int ac);
/* action 에러 여부 확인 */
void	error_commands(char *str);
/* 정렬 1단계 */
void	do_pre_commands(t_pushlist **push, t_list *commands);
/* 정렬 2단계 : 정렬 실행 */
void	check_already_done_bonus(t_pushlist **push);
/* 정렬 3단계 : 정렬 상태 확인 */
void	check_already_done_bonus(t_pushlist **push);
/* 정렬 3-2단계 : 내부 정렬 상태 점검 */
int		check_score_already_done(t_node *tmpa, int max_len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_best_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:13:19 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 01:16:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_score_siwtcher(t_pushlist **push, int value)
{
	int	score_a;
	int	score_b;
	int	ret;

	score_a = check_score_a((*push)->stack_a, value);
	score_b = check_score_b((*push)->stack_b, value, (*push)->len_b);
	if ((score_a > 0 && score_b > 0) || (score_a < 0 && score_b < 0))
		ret = get_score_for_both_same(score_a, score_b);
	else
	{
		if (score_a < 0)
			score_a *= -1;
		else if (score_b < 0)
			score_b *= -1;
		ret = score_a + score_b;
	}
	return (ret);
}

void	check_best_choice(t_pushlist **push)
{
	int			length_b;
	int			*score_b;
	t_node		*tmpb;
	int			i;

	tmpb = (*push)->stack_b;
	length_b = (*push)->len_b;
	score_b = array_malloc_to_zero(length_b);
	i = 0;
	while (i < length_b)
	{
		score_b[i] = check_score_siwtcher(push, tmpb->data);
		tmpb = tmpb->next;
		i++;
	}
	find_minimun(score_b, length_b, &i);
	lis_algorithm(push, i);
	free(score_b);
	if ((*push)->len_b != 0)
		check_best_choice(push);
	else
		return ;
}

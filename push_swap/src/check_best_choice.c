/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_best_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:13:19 by haryu             #+#    #+#             */
/*   Updated: 2022/04/21 21:56:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_score_a(t_node *stack, int value)
{
	int	i;
	int	stack_min;
	int	mid;
	int	stack_len;

	i = 1;
	stack_len = ft_push_lstsize(stack) + 1;
	mid = (stack_len) / 2;
	stack_min = ft_push_min(stack);
	while (i < stack_len)
	{
		if (stack->data < value)
		{
			if (stack->next == NULL)
				break ;
			else if (stack->next->data > value)
				break ;
			else if (stack->next->data == stack_min)
				break ;
		}
		stack = stack->next;
		i++;
	}
	if (i > mid)
		i = (stack_len - i - 1) * -1;
	return (i);
}

int	check_score_b(t_node *stack, int value, int len_b)
{
	int	i;
	int	mid;

	if (len_b == 1)
		return (0);
	i = 0;
	mid = len_b / 2;
	while (i < len_b)
	{
		if (stack->data == value)
			break ;
		stack = stack->next;
		i++;
	}
	if (i >= mid)
		i = (len_b - i) * -1;
	return (i);
}

int	check_score_siwtcher(t_pushlist **push, int value)
{
	int	score_a;
	int	score_b;
	int	ret;
	int	i;

	score_a = check_score_a((*push)->stack_a, value);
	score_b = check_score_b((*push)->stack_b, value, (*push)->len_b);
	i = 0;
	if (score_a > 0 && score_b > 0)
	{
		while (i < score_a && i < score_b)
			i++;	
		ret = score_a + score_b - i;
	}
	else if (score_a < 0 && score_b < 0)
	{
		while (i > score_a && i > score_b)
			i--;
		ret = (score_a + score_b - i) * -1;
	}
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

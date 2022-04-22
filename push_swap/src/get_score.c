/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:11:32 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 01:24:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_standard_for_a(t_node *stack, int value, int length, int limit)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (stack->data < value)
		{
			if (stack->next == NULL)
				break ;
			else if (stack->next->data > value)
				break ;
			else if (stack->next->data == limit)
				break ;
		}
		stack = stack->next;
		i++;
	}
	return (i);
}

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
	i = check_standard_for_a(stack, value, stack_len, stack_min);
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

int	get_score_for_both_same(int score_a, int score_b)
{
	int	ret;
	int	i;

	ret = 0;
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
	return (ret);
}

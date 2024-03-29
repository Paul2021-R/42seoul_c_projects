/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:01:32 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 16:55:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

int	ft_push_lstsize(t_node *lst)
{
	int		ret;

	ret = 0;
	while (lst)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}

t_node	*ft_push_lstlast_early(t_node *lst)
{
	int	limit;

	limit = ft_push_lstsize(lst) - 2;
	while (limit && lst)
	{
		lst = lst->next;
		limit--;
	}
	return (lst);
}

int	ft_push_min(t_node *stack)
{
	int	ret;

	ret = stack->data;
	while (stack)
	{
		if (ret > stack->data)
			ret = stack->data;
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	return (ret);
}

int	ft_push_max(t_node *stack)
{
	int	ret;

	ret = stack->data;
	while (stack)
	{
		if (ret < stack->data)
			ret = stack->data;
		stack = stack->next;
	}
	return (ret);
}

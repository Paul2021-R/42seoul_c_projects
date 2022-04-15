/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:01:32 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 00:08:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_push_lstdelone(t_node *lst)
{
	lst->data = 0;
	lst->next = 0;
	free(lst);
	return ;
}

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

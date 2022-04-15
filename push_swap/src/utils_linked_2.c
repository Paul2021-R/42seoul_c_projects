/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:01:32 by haryu             #+#    #+#             */
/*   Updated: 2022/04/15 09:01:51 by haryu            ###   ########.fr       */
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

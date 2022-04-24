/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:45:15 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 16:55:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

t_node	*ft_push_lstnew(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

t_node	*ft_push_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_push_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_push_lstlast(*lst);
	new->next = last->next;
	last->next = new;
}

void	ft_push_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

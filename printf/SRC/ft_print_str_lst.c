/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:59:13 by haryu             #+#    #+#             */
/*   Updated: 2022/01/16 14:37:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_str_lst(t_list *first)
{
	while (first->next)
	{
		ft_putstr((char *)first->content);
		first = first->next;
	}
	return ;
}

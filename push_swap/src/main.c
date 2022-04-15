/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:14:33 by haryu             #+#    #+#             */
/*   Updated: 2022/04/15 09:02:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_pushlist	*push_swaper;

	if (ac < 2)
		put_error();
	push_swaper = malloc(sizeof(t_pushlist) * 1);
	if (!push_swaper)
		put_error();
	push_swaper->max_len = ac - 1;
	push_swaper->array = error_check(ac, av);
	fill_stack(&push_swaper, ac);
	lst_print(&push_swaper);
}

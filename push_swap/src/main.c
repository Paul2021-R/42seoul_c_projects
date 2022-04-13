/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:17:48 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 00:50:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_pushlist	*stack_a;
	t_pushlist	*stack_b;

	if (ac < 2)
		put_error();
	stack_a = malloc(sizeof(t_pushlist) * 1);
	stack_a = malloc(sizeof(t_pushlist) * 1);
	fill_stack(error_check(ac, av), stack_a, ac);
	fill_stack_empty(0, stack_b, ac);
	lst_print(&stack_a, &stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:17:48 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 01:27:37 by haryu            ###   ########.fr       */
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
/*
스택 b를 먼저 할당을 해두면, 공간 확보를 편리하게 할 수는 있을지 모르겠지만. 실질적으로 0 값이 들어왔을 때, 실제 0과 0이 아닌 값 사이에 구분이 어렵다. 
초기화를 위해 0을 넣을 경우 나중에 실제 값 비교 및 위치 선정에 있어서 매우 곤란하다. 
따라서, 오늘 가서 실제 구현 시 stack b는 필요 시 추가 할당을 하는 방식으로 진행 해야 하리라 생각된다. 
*/
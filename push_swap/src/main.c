/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:14:33 by haryu             #+#    #+#             */
/*   Updated: 2022/04/18 04:46:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	make_stack_a_to_lis_up(t_pushlist **push)
{
	int	i;
	int	j;
	int check;

	i = 0;
	while (i < (*push)->lis_len)
	{
		check = 0;
		j = 0;
		while(j < (*push)->lis_len)
		{
			if ((*push)->stack_a->data == (*push)->array[j])
			{
				i++;
				check = 1;
			}
			j++;
		}
		if (check == 0)
		{
			pb(push);
			//lst_print(push);
			continue ;
		}
		ra(push, 0);
		//lst_print(push);
	}
	return ;
}

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
	get_lis(&push_swaper);
	lis_print(&push_swaper);
	lst_print(&push_swaper);
	make_stack_a_to_lis_up(&push_swaper);
	//where_is_lis_a(&push_swaper);
	lst_print(&push_swaper);
	return (0);
}

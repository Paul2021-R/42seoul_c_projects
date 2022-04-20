/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:14:33 by haryu             #+#    #+#             */
/*   Updated: 2022/04/20 23:45:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	make_stack_a_to_lis_ra(t_pushlist **push)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (i < (*push)->max_len)
	{
		check = 0;
		j = 0;
		while (j < (*push)->lis_len)
		{
			if ((*push)->stack_a->data == (*push)->array[j++])
			{
				i++;
				ra(push, 0);
				check = 1;
			}
		}
		if (check == 0)
			pb(push);
		if (ft_push_lstsize((*push)->stack_a) == (*push)->lis_len)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_pushlist	*push_swaper;
	int			min_pos;
	int			min_value;

	if (ac < 2)
		put_error();
	push_swaper = malloc(sizeof(t_pushlist) * 1);
	if (!push_swaper)
		put_error();
	push_swaper->max_len = ac - 1;
	push_swaper->array = error_check(ac, av);
	fill_stack(&push_swaper, ac);
	get_lis(&push_swaper);
	make_stack_a_to_lis_ra(&push_swaper);
	check_best_choice(&push_swaper);
	min_value = ft_push_min((push_swaper)->stack_a);
	min_pos = where_is_node((push_swaper)->stack_a, min_value);
	align_stack_a(&push_swaper, min_value, min_pos);
	return (0);
}


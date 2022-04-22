/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:14:33 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 04:23:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/forbiden.h"

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

int	check_height(char **target)
{
	int	i;

	i = 0;
	while (target[i])
		i++;
	return (i);
}

char	**make_target(int ac, char **av, t_pushlist **push)
{
	char	**ret;
	char	*tmp;
	char	*tmp2;

	if (ac != 2)
	{
		(*push)->max_len = ac - 1;
		ret = av;
	}
	if (ac == 2)
	{
		tmp = ft_strjoin(av[0], " ");
		tmp2 = ft_strjoin(tmp, av[1]);
		free(tmp);
		ret = ft_split(tmp2, ' ');
		(*push)->max_len = check_height(ret) - 1;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_pushlist	*push_swaper;
	int			min_pos;
	int			min_value;
	char		**target;

	if (ac < 2)
		put_error();
	push_swaper = malloc(sizeof(t_pushlist) * 1);
	if (!push_swaper)
		put_error();
	target = make_target(ac, av, &push_swaper);
	push_swaper->array = error_check(push_swaper->max_len + 1, target);
	fill_stack(&push_swaper, push_swaper->max_len + 1);
	check_already_done(&push_swaper);
	if (ft_push_lstsize(push_swaper->stack_a) <= 3)
		exception_lis(&push_swaper);
	if (push_swaper->lis_len <= 2 && push_swaper->max_len == 5)
		exception_lis_2(&push_swaper);
	get_lis(&push_swaper);
	make_stack_a_to_lis_ra(&push_swaper);
	check_best_choice(&push_swaper);
	min_value = ft_push_min((push_swaper)->stack_a);
	min_pos = where_is_node((push_swaper)->stack_a, min_value);
	align_stack_a(&push_swaper, min_value, min_pos);
	return (0);
}

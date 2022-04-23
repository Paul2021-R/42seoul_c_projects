/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:28:51 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 17:31:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"
#include "../includes/forbiden.h"

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
	t_pushlist	*push;
	void		*command;
	t_list		*commands;
	char		**target;

	if (ac < 2)
		put_error();
	push = malloc(sizeof(t_pushlist) * 1);
	if (!push)
		put_error();
	target = make_target(ac, av, &push);
	push->array = error_check(push->max_len + 1, target);
	fill_stack(&push, push->max_len + 1);
	commands = ft_lstnew(NULL);
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		error_commands((char *)command);
		ft_lstadd_back(&commands, ft_lstnew (command));
	}
	do_pre_commands(&push, commands->next);
}

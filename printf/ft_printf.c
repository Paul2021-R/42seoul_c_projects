/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:23:25 by haryu             #+#    #+#             */
/*   Updated: 2022/01/15 21:08:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_len(char *str, va_list ap, t_list **head);
static void	switch_to_flags(char *str, va_list ap, t_list **head);
static void char_pointer_clear(void *str);

int	ft_printf(const char *str, ...)
{
	int 			ret_len;
	t_list			*print_head;
	va_list			ap;

	if (!str)
		return (0);
	va_start(ap, str);
	ret_len = 0;
	print_head = ft_lstnew(0);
	ret_len = make_len((char *)str, ap, &print_head);
	if (ret_len < 0 )
		return (0);
	//print_str(print_head);
	va_end(ap);
	return (ret_len);
}

static int	make_len(char *str, va_list ap, t_list **head)
{
	int		i;
	int		last_pick;
	t_list	*temp;
	t_list	*now;

	i = 0;
	last_pick = 0;
	while (str[i])
	{
		while (str[i] != '%' || !str[i])
		{
			temp = ft_lstlast((*head));
			if(str[i + 1] == '%' || str [i+1] == '\0')
			{
				now = ft_lstnew(0);
				now->content = (void *)ft_strndup\
							   (str + last_pick, i - last_pick + 1);
				last_pick = i + 1;
				ft_lstadd_back (&temp, now);
				break ;
			}
			i++;
		}
		if (str[i] == '%')
		{
			switch_to_flags(str + i, ap, head);
			last_pick = i + 2;
			i++;
		}
		i++;
	}
	//return (ft_str_lst_len(head));
}

static void	switch_to_flags(char *str, va_list ap, t_list **head)
{
	
	t_list	*temp;
	t_list	*now;

	temp = ft_lstlast(*head);
	if (str[1] == 'c')
	{}
	else if (str[1] == 's')
	{}
	else if (str[1] == 'd' || str[1] == 'i' || str[1] == 'u')
	{}
	else if (str[1] == 'x' || str [1] == 'X' || str[1] == 'p')
	{}
	else
	{}	
	if (!now->content)
		ft_lstclear(head, char_pointer_clear);
}

static void	char_pointer_clear(void *str)
{
	free(&str);
	str = '\0';
	return ;
}

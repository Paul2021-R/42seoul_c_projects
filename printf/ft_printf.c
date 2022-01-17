/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:23:25 by haryu             #+#    #+#             */
/*   Updated: 2022/01/17 16:34:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		make_len(char *str, va_list ap, t_list **head);
static void		switch_to_flags(char *str, va_list ap, t_list **head);
static void		char_pointer_clear(void *str);
static int		ft_str_lst_len(t_list *first);

int	ft_printf(const char *str, ...)
{
	int			ret_len;
	t_list		*print_head;
	va_list		ap;

	if (!str)
		return (0);
	va_start(ap, str);
	ret_len = 0;
	print_head = ft_lstnew(0);
	ret_len = make_len((char *)str, ap, &print_head);
	if (ret_len < 0)
		return (0);
	ft_print_str_lst(print_head->next);
	ft_lstclear(&print_head, char_pointer_clear);
	va_end(ap);
	return (ret_len);
}

static int	make_len(char *str, va_list ap, t_list **head)
{
	int		i;
	int		last_pick;
	t_list	*now;

	i = -1;
	last_pick = 0;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			while (str[i] && str[i] != '%')
				i++;
			now = ft_lstnew(ft_strndup(str + last_pick, (i - last_pick)));
			last_pick = i;
			ft_lstadd_back (head, now);
		}
		if (str[i] == '%')
		{
			switch_to_flags(str + i, ap, head);
			last_pick = 2 + i++;
		}
	}
	return (ft_str_lst_len((*head)->next));
}

static void	switch_to_flags(char *str, va_list ap, t_list **head)
{	
	t_list	*now;

	if (str[1] == 'c')
		now = ft_lstnew(ft_chartostr(va_arg(ap, int)));
	else if (str[1] == 's')
		now = ft_lstnew(ft_strdup(va_arg(ap, char *)));
	else if (str[1] == 'd' || str[1] == 'i' || str[1] == 'u')
		now = ft_lstnew(switch_integer(va_arg(ap, long long), str[1]));
	else if (str[1] == 'x' || str [1] == 'X' || str[1] == 'p')
		now = ft_lstnew(switch_integer_16(va_arg(ap, long long), str[1]));
	else if (str[1] =='%')
		now = ft_lstnew(ft_chartostr('%'));
	if (!now->content)
		ft_lstclear(head, char_pointer_clear);
	ft_lstadd_back(head, now);
}

static void	char_pointer_clear(void *str)
{
	free(str);
	str = NULL;
	return ;
}

static int	ft_str_lst_len(t_list *first)
{
	int	total_length;

	total_length = 0;
	if (!first)
		return (-1);
	while (first->next)
	{
		if (first == NULL)
			break;
		total_length += ft_strlen((char *)(first->content));
		first = first->next;
	}
	return (total_length);
}
